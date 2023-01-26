# Testing AUR-CBI-MDL-0080

**1. Steps:**

* Build the project with "make leon3 release" command
* Run the followind commands:

    n7s-sis -gdb -port 1222 -leon3 -uart1 stdio ../work/binaries/partition_1 &
    sparc-rtems6-gdb -x gdb.txt ../work/binaries/partition_1

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with the number of nanoseconds elapsed from the start of the program
