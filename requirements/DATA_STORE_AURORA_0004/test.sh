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

if ! grep -q "Create ok" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "Retrieve OK" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "Update ok" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "Delete ok" output.txt
then
	echo "FAIL"
	exit 1
fi

if ! grep -q "test succeed" output.txt
then
	echo "FAIL"
	exit 1
fi

if grep -q "Unexpected datastore behaviour" output.txt
then
	echo "FAIL"
	exit 1
fi

echo "OK"
