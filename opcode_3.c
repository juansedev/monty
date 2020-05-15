#include "monty.h"
/**
 * fn_mod - divides the second top element of the stack by the
 * top element of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: EXIT_FAILURE or return to function
 */
void fn_mod(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (dlistint_len(*stack) >= 2)
	{
		mod_topnode(stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n",
			line_global.number_line);
	exit(EXIT_FAILURE);
}
/**
 * fn_comment - doesnt do anything
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: EXIT_FAILURE or return to function
 */
void fn_comment(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * fn_pchar - prints the char at the top of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: number of nodes in the linked list, 0 if empty
 */
void fn_pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack)
		print_charlist(*stack);
	else
	{
		fclose(line_global.file_i);
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n",
				line_global.number_line);
		exit(EXIT_FAILURE);
	}
}
