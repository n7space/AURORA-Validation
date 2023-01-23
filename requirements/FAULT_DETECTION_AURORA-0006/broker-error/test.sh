#!/usr/bin/env bash

set -euo pipefail

make deploymentview debug

echo "Starting process"
./work/binaries/partition_2 > output.txt 2>&1 &
PID=$!

sleep 5

echo "Sending packet"
echo -n -e "\x00a\xff" | nc -v -q1 127.0.0.1 3333

sleep 5
echo "Killing process"
kill $PID || exit 1

echo "Checking output."
if grep -q "COMMUNICATION ERROR" output.txt
then
	echo "OK"
else
	echo "FAIL"
	exit 1
fi
