#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXCHAR 1000

void fn_push(stack_t **stack, unsigned int line_number)
{
	printf("spy push\n");
}

void fn_pall(stack_t **stack, unsigned int line_number)
{
	printf("spy pall\n");
}

void fn_pint(stack_t **stack, unsigned int line_number)
{
	printf("spy pint\n");
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

	while (i < 5)
	{
		/*if (*ops[i].op == *s && s[1] == 0)*/
                if (strcmp(opcode,))
		{
			/*return (ops[i].f);*/
                        if (strcmp())
		}
		i++;
	}
	printf("Error\n");

}
int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	char str[MAXCHAR];
	char* filename = argv[1];
	char *line = NULL;
	char *tk = NULL;
	int i = 0;

	fp = fopen(filename, "r");
	if (fp == NULL){
		printf("Error: Can't open file %s",filename);
		return 1;
	}


	/* get the first token */
	//line = fgets(str, MAXCHAR, fp);
	while (!feof(fp))
	{
		line = fgets(str, MAXCHAR, fp);
		tk = strtok(line, " \t\n"); //Primer tokeni
		i = 0;
		while (tk != NULL && i < 2)
		{
			/*printf("%s \n", tk);*/
			if (strcmp(tk, "push") == 0)
			{
				printf("opcode= %s \n", tk);
				tk = strtok(NULL, " \t\n");
				printf("argument= %s\n", tk);
				i++;
			}
			i++;
		}
		//printf("%s", line);
		printf("\n");
	}
	fclose(fp);
	return 0;
}
