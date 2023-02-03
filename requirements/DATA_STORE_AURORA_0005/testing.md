# Testing DATA_STORE_AURORA_0005

**1. Steps:**

* Build the project with "make" command
* Run ./work/binaries/demo file

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with item update messages

**3. Example output**

[TASTE] Initialization completed for function TimeService
[TASTE] Initialization completed for function Client1
[TASTE] Initialization completed for function Datastore
client1: item created, key = 0
client1: item retrieved key = 0
client1: item value coefficient = 2
client1: item updated key = 0
client1: item retrieved key = 0
client1: item value coefficient = 2
client1: item updated key = 0
client1: item retrieved key = 0
client1: item value coefficient = 4
client1: item updated key = 0
client1: item retrieved key = 0
client1: item value coefficient = 6
client1: cleaned
client1: item created, key = 1
client1: item retrieved key = 1
client1: item value coefficient = 2
client1: item updated key = 1
