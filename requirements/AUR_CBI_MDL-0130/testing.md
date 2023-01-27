# Testing AUR-CBI-MDL-0130

**1. Steps:**

* Build the project with "make" command
* Run ./work/binaries/demo file

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with the following lines at the beginning:

    client1: item created 1
    client1: item created 2
    client1: item created 3
    client1: item removed 3
    client1: item created 3
    client1: item removed 3
    client1: item created 4

* The datastore capacity is set to 3 elements and after reaching the limit items oldest are being removed
