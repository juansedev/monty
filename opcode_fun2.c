#include "monty.h"
/**
 * fn_add - adds the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: EXIT_FAILURE or return to function
 */
void fn_add(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		add_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n",
			line_global.number_line);
	exit(EXIT_FAILURE);
}
/**
 * fn_sub - substract the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: EXIT_FAILURE or return to function
 */
void fn_sub(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		sub_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n",
			line_global.number_line);
	exit(EXIT_FAILURE);
}


/**
 * fn_nop - doesnt do anything
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: number of nodes in the linked list, 0 if empty
 */
void fn_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * fn_mul - multiply the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: EXIT_FAILURE or return to function
 */
void fn_mul(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		mul_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n",
			line_global.number_line);
	exit(EXIT_FAILURE);
}
/**
 * fn_divide - divides the second top element of the stack by the
 * top element of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: EXIT_FAILURE or return to function
 */
void fn_divide(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		div_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n",
			line_global.number_line);
	exit(EXIT_FAILURE);
}
