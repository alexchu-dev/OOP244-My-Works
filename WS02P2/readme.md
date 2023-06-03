# PART 2 - DIY (50%) postal-code-based population report

Write a **postal-code-based population report** program that reads series of records of postal codes and their population in Canada from a comma-separated-values file and prints a report of the postal code and their population sorted in an ascending order based on the population of the account. 

The data file is called `PCpopulations.csv` and is formatted like as follows:
  
```Text
Three First Characters of postal code
comma
population
newline
```

Example:

```Text
A0A,46587
A0B,19792
A0C,12587
A0E,22294
A0G,35266
A0H,17804
A0J,7880
A0K,26058
A0L,7643
A0M,6200
A0N,13815
A0P,13721
A0R,2543
A1A,30382
A1B,19867
```

## DIY Execution example (with the incomplete sample file)
```text
Postal Code: population
-------------------------
1- A0R:  2543
2- A0M:  6200
3- A0L:  7643
4- A0J:  7880
5- A0C:  12587
6- A0P:  13721
7- A0N:  13815
8- A0H:  17804
9- A0B:  19792
10- A1B:  19867
11- A0E:  22294
12- A0K:  26058
13- A1A:  30382
14- A0G:  35266
15- A0A:  46587
-------------------------
Population of Canada: 282439
```

Implement this program in 3 modules called `popReport`, `File` and `Population` that can accomplish the above task.  

***You may freely use/copy any logic or code needed from the PART 1 section!***

Files to submit:  
```Text
popReport.cpp <--- contains the main function, do not modify this.
File.cpp
File.h
Population.cpp
Population.h
cstring.h
cstring.cpp
```

## `File` Module

The `File` module is partially implemented. 


## `Population` Module

The `Population` module is not implemented.

There are three mandatory functions in the `Population` module. Apart from these three functions you are free to choose any method to implement this system, however you must use function overloading, reference and dynamic memory allocation since the number of records in submission will be much more that what you have for development.

Mandatory functions in this module:

- `load`: Loads data from a file, and returns `true` if data was successfully loaded, `false` otherwise. This function receives as a parameter the name of the file
    - If the file cannot be found, print the following error message: 
    ```Text
    Could not open data file: FILENAME<ENDL>
    ```

    - If the file doesn't have a correct content, print:
    ```Text
    Error: incorrect number of records read; the data is possibly corrupted!<ENDL>
    ```

- `display`: a function with no parameters that return nothing and prints the report as shown in [DIY Execution example](#diy-execution-example).

- `deallocateMemory`: a function with no parameters that return nothing and deallocate **all** dynamic memory used by the program.




## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

In the code above, you were instructed to overload the function `read` multiple times. The parameter received by these overloads is called an **out parameter**. Do some research and explain what is an **out parameter** for a function and compare it with an **in parameter**.  In your code, can you identify any function that receives an **in parameter**? Justify your answer.

You may be asked to talk about your reflection (as a presentation) in class.



## DIY Submission (part 2)

> When submitting, your program will be tested against a data file similar to <a href="DIY/PCpopulations.csv" target="_blank">PCpopulations.csv</a> but with more data (see the <a href="DIY/PCpopulationsComplete.csv" target="_blank">prof's test data file</a>).


### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.


#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **??Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty
