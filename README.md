# C Training Projects
> This repository contains some C programming projects that I created as part of my learning journey.

## Installation

To run these projects, you need to have a C compiler installed on your system. Here I use GCC.

To compile a project, navigate to its folder and run the following command:
```
make
```

This uses the custom makefile to execute the commands necessary to run the project. It should add the commands to the terminal automatically like in this 'hello' example:
```
gcc -Wall -g -c -o hello.o hello.c
gcc -Wall -g -o hiya hello.o
```

Use 'ls' command to find the new generated file and run it using:
```
./hiya
```

To clean up the project folder run:
```
make clean
```
