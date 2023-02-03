# Testing DATA_STORE_AURORA_0006

**1. Steps:**

* Build the project with "make" command
* Run ./work/binaries/demo file

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with item create and delete messages

**3. Example output**

[TASTE] Initialization completed for function TimeService
[TASTE] Initialization completed for function Client1
[TASTE] Initialization completed for function Datastore
client1: item created, key = 0
client1: item retrieved key = 0
client1: item deleted key = 0
client1: item not present
client1: item created, key = 1
client1: item retrieved key = 1
client1: item deleted key = 1
client1: item not present
client1: item created, key = 2
client1: item retrieved key = 2
client1: item deleted key = 2
client1: item not present
client1: cleaned
client1: item created, key = 3
client1: item retrieved key = 3
client1: item deleted key = 3
client1: item not present

