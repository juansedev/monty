#include "monty.h"
/**
 * mod_topnode - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: Pointed to head of a list
 *
 * Return: void
 */
void mod_topnode(stack_t **stack)
{
	stack_t *tmp = *stack;
	int data = 0;

	data = tmp->n; /* save n in data*/
	if (data == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_global.number_line);
		exit(EXIT_FAILURE);
	}
	(tmp->next)->n = (tmp->next)->n % data; /* safe result in new top node*/
	delete_dnodeint_at_index(stack, 0);
}
