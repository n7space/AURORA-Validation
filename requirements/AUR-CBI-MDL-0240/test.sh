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

if ! grep -q "Subscribed" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "Expected item 1 retrieved" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "Expected item 2 retrieved" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "Expected item 3 retrieved" output.txt
then
	echo "FAIL"
	exit 1
fi

if grep -q "Unexpected Data Store behaviou" output.txt
then
	echo "FAIL"
	exit 1
fi

if grep -q "Test failed" output.txt
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
