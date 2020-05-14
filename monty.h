#ifndef _MONTY_H_
#define _MONTY_H_

#define MAXCHAR 1000
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>


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

/**
 * struct line_s - line of file and its atributes
 * @opcode: the opcode
 * @argument: Argunment
 * @number_line: Line of the file
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct line_s
{
	char *opcode;
	char *argument;
	unsigned int number_line;
} line_t;


extern line_t line_global;
line_t line_global;

size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

int _isdigit();

void monty_script(FILE *input);
void validate_opcode();
void (*get_code_fn(char *opcode))(stack_t **stack, unsigned int line_number);

void fn_push(stack_t **stack, unsigned int line_number);
void fn_pall(stack_t **stack, unsigned int line_number);
void fn_pint(stack_t **stack, unsigned int line_number);

#endif /* monty.h */
