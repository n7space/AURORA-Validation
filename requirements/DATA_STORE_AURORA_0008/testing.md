# Testing DATA_STORE_AURORA_0008

**1. Steps:**

* Build the project with "make" command
* Run ./work/binaries/demo file

**2. Expected results:**

* Project should succesfully build
* The running binary should output logs in a loop with item log messages

**3. Example output**

[TASTE] Initialization completed for function TimeService
[TASTE] Initialization completed for function Client1
[TASTE] Initialization completed for function Datastore
client1: item created, key = 1
client1: log data from index 0
client1: log data store item created
client1: item deleted key = 1
client1: log data from index 0
client1: log data store item delete
client1: item created, key = 2
client1: log data from index 0
client1: log data store item created
client1: item deleted key = 2
client1: log data from index 0
client1: log data store item delete
client1: item created, key = 3
client1: log data from index 0
client1: log data store item created
client1: item deleted key = 3
client1: log data from index 0
client1: log data store item delete
client1: cleaned
client1: log data from index 6
client1: log data store item created
client1: log data from index 5
client1: log data store item delete
client1: log data from index 4
client1: log data store item created
client1: log data from index 3
client1: log data store item delete
client1: log data from index 2
client1: log data store item created
client1: log data from index 1
client1: log data store item delete
