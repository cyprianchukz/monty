0x19. C - Stacks, Queues - LIFO, FIFO
C
Group project
Algorithm
Data structure
 By: Julien Barbier
 Weight: 2
 Project to be done in teams of 2 people (your team: Cyprian Ikogwe)
 Project will start Dec 12, 2023 6:00 AM, must end by Dec 15, 2023 6:00 AM

Resources
Read or watch:

Google
How do I use extern to share variables between source files in C?
Stacks and Queues in C
Stack operations
Queue operations
Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
What do LIFO and FIFO mean
What is a stack, and when to use it
What is a queue, and when to use it
What are the common implementations of stacks and queues
What are the most common use cases of stacks and queues
What is the proper way to use global variable

Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You allowed to use a maximum of one global variable
No more than 5 functions per file
You are allowed to use the C standard library
The prototypes of all your functions should be included in your header file called monty.h

The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

The monty program

Usage: monty file
where file is the path to the file containing Monty byte code
If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number where the instruction appears.
Line numbers always start at 1
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured
If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
