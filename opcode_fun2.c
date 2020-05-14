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
	if (stack && *stack && (dlistint_len(*stack) > 2))
        {
                add_topnode(stack);
                return;
        }
	dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n",
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
	(void)line_number;
	print_dlistint(*stack);
}
