#!/usr/bin/env bash

check_output ()
{
	echo "Checking output ($1)"

	if ! grep -q "Subscribed" $1
	then
		echo "FAIL"
		exit 1
	fi

	if ! grep -q "Create ok" $1
	then
		echo "FAIL"
		exit 1
	fi

	if ! grep -q "Retrieve OK" $1
	then
		echo "FAIL"
		exit 1
	fi

	if ! grep -q "Log retrieve OK" $1
	then
		echo "FAIL"
		exit 1
	fi

	echo "OK"
}

set -euo pipefail

pushd data-store
make clean
make linux debug
popd

echo "Starting process on Linux"
./data-store/work/binaries/demo > output.txt 2>&1 &
PID=$!

sleep 10

echo "Killing process"
kill $PID || exit 1

pushd data-store
make clean
make leon3 debug

echo "Starting process on Leon3"
pushd scripts
./leon-run.sh > ../../output-leon.txt 2>&1 &

sleep 10

popd
make clean
popd

check_output output.txt
check_output output-leon.txt
