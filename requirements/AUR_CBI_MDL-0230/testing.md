# Testing AUR-CBI-MDL-0230

**1. Steps:**

* Build the project with "make" command
* Run ./work/binaries/demo file

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with newly received items
* At 5th loop, item with key = 0 will be deleted
* At 7th loop, item with key = 1 will updated
* At 6th and after 8 loops onward, item with key = 2 will be retrieved for verification
