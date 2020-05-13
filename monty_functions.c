#include "monty.h"

void fn_push(stack_t **stack, unsigned int line_number)
{
	(void)stack;
  (void)line_number;
  
  printf("spy push\n");
}

void fn_pall(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;

	printf("spy pall\n");
}

void fn_pint(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;

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

	while (i < 4)
	{
    if (strcmp(opcode,ins_code[i].opcode) == 0)
		{
			return (ins_code[i].f);
		}
		i++;
	}
	printf("Error\n");
  return NULL;
}
