#include "monty.h"

void fn_push(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	printf("spy push\n");
}

void fn_pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	printf("spy pall\n");
}

void fn_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	printf("spy pint\n");
}
