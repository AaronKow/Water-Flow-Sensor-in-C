# Water-Flow-Sensor-in-C
This repository is about using C Programming to read water flow sensor (model part YF-S201C or model YF-S201) data with embedded Linux board. The tested hardware for this source code is Artik 10 from Samsung. I also wrote a tutorial about how to use water flow sensor to work with Artik 10, you can view the tutorial, [here](https://www.hackster.io/aaronkow/read-water-flow-sensor-using-artik-10-with-c-programming-578436).

## Who Should Follow this Tutorial
Any person who wanted to try out the water flow sensor with model part YF-S201C or model YF-S201 with C programming for their embedded Linux board. ***If you have try out the water flow sensor with my code, please kindly feedback me with the result, so I can improve it***. Thanks!

## Prerequisite
As long as your machine is an embedded Linux board and able to compile C program file, it is okay. To compile the C program file, you need a compiler called "GCC compiler" from [GNU](https://gcc.gnu.org).

## How to Use
The coding is much self-explanatory, I have included comments in the code. First, you need to configure the calibration factor to suit to your own embedded board:

```c
// in water_flow.c, line 41:
calibration_factor = 5.0;		// change the factor to suit your board
```

Please note that, you need to tells the compiler to link with the pthread library, which purpose for compilation for threads. You can do it as below:

```sh
$ gcc main.c water_flow.c interrupt.c -o water_flow -lpthread
```

In the execution file, it requires an argument. The argument represent the GPIO pin of your embedded device that connect the signal pin of the water flow sensor. During execution, you need to follow this command:

```sh
$ ./water_flow <GPIO-Pin-to-Water-Flow-Sensor>
```

Example to execute it with pin 13 for Artik 10:
```sh
$ ./water_flow 22
```

Finally, in the terminal you should be able to see output as below:
```sh
Program Started ...
Please press <enter> to exit this program.
Flow rate: 0.000000 L/min; Current Liquid Flowing: 0 ml/sec; Output Liquid Quantity: 0 ml
Flow rate: 0.000000 L/min; Current Liquid Flowing: 0 ml/sec; Output Liquid Quantity: 0 ml
```

**Please note that, you must press "ENTER" to stop this program. Because this will successfully unexport your reference pin for the next execution.**

## License
The license of this project is under MIT License, see the LICENSE for more information.