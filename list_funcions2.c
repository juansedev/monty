#include "monty.h"
/**
 * dlistint_len - Function that count all the elements of a dlistint_t list
 * @h: Pointed to head of a list
 *
 * Return: The number of nodes
 */
size_t dlistint_len(const stack_t *h)
{
	const stack_t *tmp = h;
	size_t nodes = 0;

	if (tmp == NULL)
	{
		return (0);
	}

	while (tmp)
	{
		nodes++;
		tmp = tmp->next;
	}
	return (nodes);
}

/**
 * swap_node - changes two nodes
 * @stack: Pointed to head of a list
 *
 * Return: void
 */
void swap_node(stack_t *stack)
{
	stack_t *tmp = stack;
	int data = 0;

	data = tmp->n; /* save n  in data*/
	tmp->n = (tmp->next)->n;
	(tmp->next)->n = data;
}
/**
 * add_topnode - add top stack
 * @stack: Pointed to head of a list
 *
 * Return: void
 */
void add_topnode(stack_t **stack)
{
	stack_t *tmp = *stack;
	int data = 0;

	data = tmp->n; /* save n  in data*/
	(tmp->next)->n += data; /* safe result in new top node*/
	delete_dnodeint_at_index(stack, 0);
}
