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

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s", filename);
		return (EXIT_FAILURE);
	}
	monty_script(fp);
	return (0);
}
