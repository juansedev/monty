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
	int i = 1, j = 0, lines = 0;
	char *code = NULL;

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
				line_global.opcode = tk_argument;
				line_global.number_line = i;
			}
			if (j == 1)
				line_global.argument = atoi(tk_argument);
			tk_argument = strtok(NULL, " \t"), j++;
		}
		if (j == 1 && strcmp(line_global.opcode, "push") == 0)
		{
			lines = line_global.number_line;
			code = line_global.opcode;
			printf("L%d: unknown instruction %s\n", lines, code);
			exit(EXIT_FAILURE);
		}
		else
			line_global.argument = -1;
		if (tk_line)
			get_code_fn(line_global.opcode)(&head, line_global.number_line);
		line_global.argument = 0;
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
		{NULL, NULL}
	};
	int i = 0, line = 0;
	char *code = NULL;

	i = 0;

	while (i < 3)
	{
		if (strcmp(opcode, ins_code[i].opcode) == 0)
		{
			return (ins_code[i].f);
		}
		i++;
	}
	line = line_global.number_line;
	code = line_global.opcode;
	printf("L%d: unknown instruction %s\n", line, code);
	exit(EXIT_FAILURE);
}
