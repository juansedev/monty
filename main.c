#include "monty.h"

/**
 *
 *
 *
 */
int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	char str[MAXCHAR];
	char* filename = argv[1];
	char *line = NULL;
	char *tk = NULL;
	int i = 0;
  (void)argc;

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
				printf("opcode= %s\n", tk);
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
