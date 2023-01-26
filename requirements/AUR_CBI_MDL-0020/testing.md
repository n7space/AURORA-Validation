# Testing AUR-CBI-MDL-0080

**1. Steps:**

* Build the project with "make leon3 release" command
* Go to the "scripts" directory
* Execute script ./leon-run.sh

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with the number of nanoseconds elapsed from the start of the program
