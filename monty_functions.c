#include "monty.h"
/**
 *
 * 
 * 
 */
void monty_script(FILE *input)
{
	char *line = NULL;/*, *copy_line = NULL;*/
	char *tk = NULL;
	char str[MAXCHAR];
	int i = 1;/*, lines = 0;*/
	/*void fn_opcode;*/

	while (!feof(input))
	{
		line = fgets(str, MAXCHAR, input);
		tk = strtok(line, "\n");
		printf("number= %d line= %s\n", i, tk);	
		tk = strtok(NULL, "\n");
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
