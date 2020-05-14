#include "monty.h"
/**
 *
 * 
 * 
 */
void monty_script(FILE *input)
{
	char *line = NULL;/*, *copy_line = NULL;*/
	char *tk_argument = NULL;
	char *tk_line = NULL;
	char str[MAXCHAR];
	char *codestring = NULL;
	stack_t *head;
	int i = 1, j = 0;/*, lines = 0;*/


	while (!feof(input))
	{
		line = fgets(str, MAXCHAR, input);
		tk_line = strtok(line, "\n");
		/*printf("number= %d line= %s\n", i, tk_line);*/

		tk_argument = strtok(tk_line, " \t");
		/*printf("argument line= %s\n", tk_argument); */
		j = 0;
		while (tk_argument && tk_line && j < 2) /* pend valid arguments < 2*/
		{
			if (j == 0)
				codestring = tk_argument;
			if (j == 1)
				argument = atoi(tk_argument);
			/*printf("number line= %d argument = %s\n", i, tk_argument);*/
			tk_argument = strtok(NULL, " \t");
			j++;
		}
		if (j == 1)
			argument = -1;
		/*printf("global var = %d\n opcode = %s\n", argument, codestring);*/
		if (tk_line)
			get_code_fn(codestring)(&head, i);
		argument = 0;
		tk_line = strtok(NULL, "\n");
		i++;
	}
	fclose(input);
}

/**
 *
 * 
 * 
 */
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

	while (i < 3)
	{
		if (strcmp(opcode, ins_code[i].opcode) == 0)
		{
			return (ins_code[i].f);
		}
		i++;
	}
	printf("Error\n");
	exit(0);
}
