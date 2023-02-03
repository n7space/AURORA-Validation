# AUR-CBI-INT-0070
It shall be possible to include a CBI Model compliant component in a standalone application that does not depend on a TASTE runtime

This directory contains two projects:
 * taste-project: a TASTE project which contains one Simulink function and one C functions, selected to be standalone components, the other functions exist to check if project works as expected
 * standalone-project: a C project which contains the two selected components from taste-project and a C code which uses these components

# Building & testing

## taste-project

Use spacecreator to build and run the project. The taste-project contains a GUI function, so after staring, the window shall appear.

## standalone-project

To compile the project use the `make` command:
```
cd standalone-project
make
```

To run the project launch created executable in the terminal:
```
./bin/main
```

The standalone-project is a console application. Every second it should print the status reported by controller component:
```
[TASTE] Initialization completed for function algorithms
[TASTE] Initialization completed for function controller
Status | Temp: 305.000000 | Flow: 0.000000 | Capacity: 0.480000 | Voltage: 5.000000 | Current: 0.000000
Status | Temp: 303.772546 | Flow: 0.800000 | Capacity: 0.480880 | Voltage: 4.064069 | Current: 0.203103
Status | Temp: 302.388167 | Flow: 0.536393 | Capacity: 0.481794 | Voltage: 3.492531 | Current: 0.173784
```

To test the standalone-project run the following commands:
```
make test
```
