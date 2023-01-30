#!/usr/bin/env bash

set -euo pipefail

pushd data-store
make debug
popd

echo "Starting process"
./data-store/work/binaries/demo > output.txt 2>&1 &
PID=$!

sleep 10

echo "Killing process"
kill $PID || exit 1

echo "Checking output."

if ! grep -q "Checking create on full Data Store" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "Store rejected as expected" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "Test succeed" output.txt
then
	echo "FAIL"
	exit 1
fi

echo "OK"
