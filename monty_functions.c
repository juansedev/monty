#include "monty.h"

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
                if (strcmp(opcode,ins_code[i]) == 0)
		{
			return (ins_code[i].f);
		}
		i++;
	}
	printf("Error\n");

}