# 0x19. C - Stacks, Queues - LIFO, FIFO

## Resources
#### Read or watch:

* Google
* [How do I use extern to share variables between source files in C?](https://intranet.hbtn.io/rltoken/9neX6gaN6DoA-ow1INgZqw)

# Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General
* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables


# Requirements
## General
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the C standard library
* The prototypes of all your functions should be included in your header file called ``monty.h``
* Dont forget to push your header file
* All your header files should be include guarded
* You are expected to do the tasks in the order shown in the project


# More Info
## Data structures

Please use the following data structures for this project. Dont forget to include them in your header file.


```C
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```

```C
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
# Compilation & Output
* Your code will be compiled this way:

````bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
````

* Any output must be printed on stdout
* Any error message must be printed on stderr: Here is a link to a [GitHub repository](https://intranet.hbtn.io/rltoken/9RfVU4j7qVbFgGdMkpX2qA) that could help you making sure your errors are printed on stderr

# Tests
We strongly encourage you to work all together on a set of tests

# The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. 

### The goal of this project is to create an interpreter for Monty ByteCodes files.

## The monty program

* Usage: ``monty file``: where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message ``USAGE: monty`` file, followed by a new line, and exit with the status ``EXIT_FAILURE``
* If, for any reason, its not possible to open the file, print the error message ``Error: Can't open file <file>``, followed by a new line, and exit with the status ``EXIT_FAILURE``; where <file> is the name of the file
* If the file contains an invalid instruction, print the error message ``L<line_number>: unknown instruction <opcode>``, followed by a new line, and exit with the status ``EXIT_FAILURE``:
- where is the line number where the instruction appears.
- Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
- it executed properly every line of the file
- it finds an error in the file
- an error occured
If you cant malloc anymore, print the error message ``Error: malloc failed``, followed by a new line, and exit with status ``EXIT_FAILURE``.
You have to use ``malloc`` and ``free`` and are not allowed to use any other function from ``man malloc`` (realloc, calloc, )

![](https://img.huffingtonpost.com/asset/5cc2067b240000130a522256.jpeg?ops=scalefit_630_noupscale)

## EXAMPLES OUTPUTS WITH OUR MONTY

### Project by [Juan Llano](https://twitter.com/@llanoJS) & [Crispthofer Rincon](https://twitter.com/CrispthoAlex) to [Holberton School](https://www.holbertonschool.com/) Cohort 11