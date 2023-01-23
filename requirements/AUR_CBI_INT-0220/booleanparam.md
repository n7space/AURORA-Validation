# Testing function with boolean type param

**1. Steps:**

* Build the project
* Open project `tests/manual/functiontester/projects/booleanparam/booleanparam.pro`
* Open the `interfaceview.xml` file
* Select an interface by clicking on the arrow
* Select Tools -> Test Interface -> Test using data from CSV
* Select x86 Linux CPP
* Click OK
* Choose csv file with test vectors
* Set max delta and click OK to accept

**2. Expected results:**

* Project should succesfully build
* It should launch the default browser with a page displaying results in the form of the array
* All the numbers should be green and there should be no missing cells and no error info
