# Testing automatic simulink model generation

**1. Steps:**

* Open project `QgenC.pro`
* Open the `interfaceview.xml` file
* Right click on the interfaceview and select the "Generate/update code skeletons" option
* Go into `work/simulink/QGenC`
* Run `make ./src/interfaceBasic%slx`

Expected results:

* Simulink skeleton model should appear in `work/simulink/qgenc/src/interfaceBasic.slx`
