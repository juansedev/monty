#include "monty.h"
/**
 * monty_script - This function split the input file in line  and arguments
 * and later invoke the function acording opcode input.
 * @input: File to read.
 *
 * Return: Void
 */
void monty_script(FILE *input)
{
	char *line = NULL;
	char *tk_argument = NULL;/* *tk_line = NULL;*/
	char str[MAXCHAR];
	stack_t *head = NULL;
	int i = 1, j = 0;

	line_global.file_i = input;
	line_global.opcode = NULL;
	line = fgets(str, MAXCHAR, input);
	while (!feof(input))
	{

		tk_argument = strtok(line, " \t\n");
		j = 0;
		while (tk_argument && j < 2)
		{
			if (j == 0)
			{
				if (tk_argument[0] == '#')
				{
					line_global.opcode = "#"; /* safe argument*/
					i--;
				}
				else
					line_global.opcode = tk_argument; /* safe argument*/
				line_global.number_line = i; /*safe number_line */
			}
			if (j == 1)
				line_global.argument = tk_argument;
			tk_argument = strtok(NULL, " \t\n"), j++;
		}
		if (line_global.opcode)
			get_code_fn(line_global.opcode)(&head, line_global.number_line);
		line_global.argument = NULL;
		line_global.opcode = NULL, i++;
		line = fgets(str, MAXCHAR, input);
	}
	free_dlistint(head), fclose(input);
}
/**
 * get_code_fn - Pointer to function to select a correct funcion
 * acording input opcode
 * @opcode: String with name of the opcode
 *
 * Return: Void
 */
void (*get_code_fn(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ins_code[] = {
		{"push", fn_push},
		{"pall", fn_pall},
		{"pint", fn_pint},
		{"pop", fn_pop},
		{"swap", fn_swap},
		{"add", fn_add},
		{"nop", fn_nop},
		{"sub", fn_sub},
		{"mul", fn_mul},
		{"div", fn_divide},
		{"mod", fn_mod},
		{"#", fn_comment},
		{"pchar", fn_pchar},
		{NULL, NULL}
	};
	int i = 0, line = 0;
	char *code = NULL;

	i = 0;

	while (ins_code[i].opcode)
	{
		if (strcmp(opcode, ins_code[i].opcode) == 0)
		{
			return (ins_code[i].f);
		}
		i++;
	}
	line = line_global.number_line, code = line_global.opcode;
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, code);
	exit(EXIT_FAILURE);
}

/**
 * _isdigit - Checked if a character is a digit character
 * Return: c if c is a digit (1) otherwise
 */
int _isdigit(void)
{
	int i;

	i = 0;
	if (line_global.argument[0] == '-')
		i++;
	while (line_global.argument[i])
	{
		if (!isdigit(line_global.argument[i]))
			return (0); /* verified each position */
		i++;
	}
	return (1);
}
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
