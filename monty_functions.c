#include "monty.h"



void monty_script(FILE *input)
{
	char *line = NULL;
	char *tk = NULL;
	char str[MAXCHAR];
	int i = 0;

	while (!feof(input))
	{
		line = fgets(str, MAXCHAR, input);
		/* Primer token */
		tk = strtok(line, " \t\n");
		i = 0;
		while (tk != NULL && i < 2)
		{
			if (strcmp(tk, "push") == 0)
			{
				printf("opcode= %s\n", tk);
				tk = strtok(NULL, " \t\n");
				printf("argument= %s\n", tk);
				i++;
			}
			i++;
		}
		printf("\n");
	}
	fclose(input);
}


void (*get_code_fn(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ins_code[] = {
		{"push", fn_push},
		{"pall", fn_pall},
		{"pint", fn_pint},
		{NULL, NULL}
	};
	int i = 0;

	i = 0;

	while (i < 4)
	{
		if (strcmp(opcode, ins_code[i].opcode) == 0)
		{
			return (ins_code[i].f);
		}
		i++;
	}
	printf("Error\n");
	return (NULL);
}
