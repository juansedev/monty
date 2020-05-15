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
	char *tk_argument = NULL, *tk_line = NULL;
	char str[MAXCHAR];
	stack_t *head = NULL;
	int i = 1, j = 0;

	line_global.file_i = input;
	while (!feof(input))
	{
		line = fgets(str, MAXCHAR, input);
		tk_line = strtok(line, "\n");
		tk_argument = strtok(tk_line, " \t");
		j = 0;
		while (tk_argument && tk_line && j < 2)
		{
			if (j == 0)
			{
				line_global.opcode = tk_argument; /* safe argument*/
				line_global.number_line = i; /*safe number_line */
			}
			if (j == 1)
				line_global.argument = tk_argument;

			tk_argument = strtok(NULL, " \t"), j++;
		}
		if (tk_line)
			get_code_fn(line_global.opcode)(&head, line_global.number_line);
		line_global.argument = NULL;
		tk_line = strtok(NULL, "\n"), i++;
	}
	free_dlistint(head);
	fclose(input);
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
	while (line_global.argument[i])
	{
		if (line_global.argument[i] == '-' && i == 0)
			continue;
		if (!isdigit(line_global.argument[i]))
			return (0); /* verified each position */
		i++;
	}
	return (1);
}
