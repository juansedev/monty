#include "monty.h"

size_t print_dlistint(const stack_t *h)
{
	const stack_t *tmp = h;
	size_t nodes = 0;

	if (tmp == NULL)
	{
		return (0);
	}

	while (tmp)
	{
		printf("%d\n", tmp->n);
		nodes++;
		tmp = tmp->next;
	}
	return (nodes);
}

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);

	}

	new_node->prev = NULL;
	new_node->next = *head;
	(*head)->prev = new_node;

	*head = new_node;
	return (*head);
}
