#include "monty.h"

/**
 * print_dlistint - print elements of linked list
 * @h: pointer to node
 * Return: number of nodes in the linked list, 0 if empty
 */
void print_dlistint(const stack_t *h)
{
	const stack_t *tmp = h;
	size_t nodes = 0;

	if (tmp == NULL)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		nodes++;
		tmp = tmp->next;
	}
}

/**
 * print_head - print first elements of linked list
 * @h: pointer to node
 * Return: void
 */
void  print_head(const stack_t *h)
{
	const stack_t *tmp = h;

	printf("%d\n", tmp->n);
}
/**
 * add_dnodeint - add a node a beggining of the linke list
 * @head: double pointer to node
 * @n: data to add in the node
 * Return: pointer to node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

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

/**
 * delete_dnodeint_at_index - Function that delete element from
 * index given of a stack_t list
 * @head: double  Pointer with the addres of head of a list
 * @index: value of the index
 *
 * Return: 1 success delete, -1 failed delete
 */
void delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *copy = *head;
	unsigned int ind_node = 0;

	if (!head || !(*head))
		return (-1);

	if (index == 0 && copy->next == NULL)
	{
		free(*head);
		*head = NULL;
		return (1);
	}
	if (index == 0 && copy->next != NULL)
	{
		*head = copy->next;
		(*head)->prev = NULL;
		free(copy);
		return (1);
	}
	while (copy)
	{
		if (ind_node == index && copy->next != NULL)
		{
			(copy->prev)->next = (copy->next);
			(copy->next)->prev = (copy->prev);
			free(copy);
			return (1);
		}
		if (ind_node == index && copy->next == NULL)
		{
			(copy->prev)->next = NULL;
			free(copy);
			return (1);
		}
		copy = copy->next;
		ind_node++;
	}
	return (-1);
}
/**
 * free_dlistint - Function that count all the elements of a dlistint_t list
 * @head: double  Pointer with the addres of head of a list
 *
 * Return: Void
 */
void free_dlistint(stack_t *head)
{
	stack_t *to_free, *tmp;

	if (head == NULL)
		return;

	to_free = head;

	while (to_free)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
}
