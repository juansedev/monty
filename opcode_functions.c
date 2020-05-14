#include "monty.h"

void fn_push(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	printf("push: %d - %d\n", line_number, argument);
}

void fn_pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	printf("pall: %d - %d\n", line_number, argument);
}

void fn_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	printf("pint: %d - %d\n", line_number, argument);
}
