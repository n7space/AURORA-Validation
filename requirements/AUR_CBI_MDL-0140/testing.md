# Testing AUR-CBI-MDL-0140

**1. Steps:**

* Build the project with "make" command
* Run ./work/binaries/demo file

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with the following output at the beginning:

    [TASTE] Initialization completed for function TimeService
    [TASTE] Initialization completed for function Client1
    [TASTE] Initialization completed for function Datastore
    client1: item created 0
    client1: item created 1
    client1: item created 2
    client1: item store rejected
    client1: item store rejected
    client1: item store rejected
    client1: item removed 0
    client1: item created 3
    client1: item removed 1
    client1: item created 4
    client1: item removed 2

* The output shows 3 items were created, then the datastore is full (capacity is set to 3) and new items are getting rejected.
    After that the settings are changed to replacing new items and the items are being replaced.
