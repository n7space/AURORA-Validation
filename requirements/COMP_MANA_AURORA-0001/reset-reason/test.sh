#!/bin/bash
echo -e "Building binary\n"
make leon3 debug
echo -e "\nExecuting binary\n"
sis-2.29 -leon3 -dumbio -uart1 system.log -rt work/binaries/leon3 < gdb.batch
echo -e "\nTest result\n"
cat system.log
