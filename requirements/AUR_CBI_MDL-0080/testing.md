# Testing AUR-CBI-MDL-0080

**1. Steps:**

* Build the project with "make" command
* Run ./work/binaries/demo file

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with two cFS timestamps and result of their comparison
* The result should be equal to 1 (since the second timestamp is later than the first)
