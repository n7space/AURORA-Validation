# CBI model integration using SpaceCreator

**Overview:**

SpaceCreator was used as base for CBI model editior implementation as per [1]

[1] AUR-N7S-RP-0001 D5_2 CBI Technical Architecture (6.1 Software design overview)

**component-management-behaviors**

* Open project `QgenC.pro`
* Open the `interfaceview.xml` file
* Functions relay behavior management communication through interfaces and connections
* All functions implement specific archetype
* Communication handling is implemented in functions implementations
* Above steps executed on 26/01/2023

**events-communication**

* Open project `QgenC.pro`
* Open the `interfaceview.xml` file
* Functions relay event communication through interfaces and connections
* All functions implement specific archetype
* EventBus function handles event dispatching
* Event communication handling is implemented in functions implementations
* Above steps executed on 26/01/2023

**layers-model**

* Open project `QgenC.pro`
* Open the `interfaceview.xml` file
* List of layers is present in top right corner of interface view
* Every interface has property with corresponding layer
* It is possible to turn off/on layer visibility
* Above steps executed on 26/01/2023

**n-to-m-model**

* Open project `QgenC.pro`
* Open the `interfaceview.xml` file
* Functions implement n-to-m communication
* Run `make` command in main project directory
* No error logs should appear
* Above steps executed on 26/01/2023

**n-to-one-error-communication**

* Open project `QgenC.pro`
* Open the `interfaceview.xml` file
* Functions relay error communication through interfaces and connections
* All functions implement specific archetype
* Error communication handling is implemented in functions implementations
* Above steps executed on 26/01/2023

**power-mode-controll**

* Open project `QgenC.pro`
* Open the `interfaceview.xml` file
* Functions relay power mode controll communication through interfaces and connections
* All functions implement specific archetype
* Communication handling is implemented in functions implementations
* Above steps executed on 26/01/2023

