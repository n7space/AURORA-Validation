# Testing AUR-CBI-MDL-0230

**1. Steps:**

* Build the project with "make" command
* Run ./work/binaries/demo file

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with newly received items
* At 4th loop, item with key = 1 will be deleted
* At 6th loop, item with key = 2 will updated
* At 5th and after 7 loops onward, item with key = 3 will be retrieved for verification
