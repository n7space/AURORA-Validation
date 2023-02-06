#!/usr/bin/env bash

set -euo pipefail

./bin/main > output.txt 2>&1 &
PID=$!

sleep 10

kill $PID || exit 1

if ! grep -q "Initialization completed for function algorithms" output.txt
then
	echo "Missing initialization of algorithms"
	exit 1
fi

if ! grep -q "Initialization completed for function controller" output.txt
then
	echo "Missing initialization of controller"
	exit 1
fi

if ! grep -E -q "Status \| Temp: " output.txt
then
	echo "Missing application output"
	exit 1
fi

if grep -q "Invalid data in status" output.txt
then
	echo "Invalid data reported by application"
fi

echo "TEST OK"
