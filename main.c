#include "monty.h"
/**
 * main - entre point
 * @argc: Amount of input arguments
 * @argv: Array of arguments
 *
 * Return: (0) exit succesfull
 */
int main(int argc, char *argv[])
{
	char *filename = argv[1];
	FILE *fp = NULL;
	(void)argc;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s", filename);
		return (1);
	}

	monty_script(fp);
	return (0);
}
