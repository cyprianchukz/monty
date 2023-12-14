#include "monty.h"
/**
* exec - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_opcode}, {"pall", pall_opcode}, {"pint", pint_opcode},
				{"pop", pop_opcode},
				{"swap", swap_opcode},
				{"add", add_opcode},
				{"nop", nop_opcode},
				{"sub", sub_opcode},
				{"div", div_opcode},
				{"mul", mul_opcode},
				{"mod", mod_opcode},
				{"pchar", cyp_pchar_opcode},
				{"pstr", cyp_pstr_opcode},
				{"rotl", cyp_rotl_opcode},
				{"rotr", cyp_rotr},
				{"queue", cyp_queue_opcode},
				{"stack", cyp_stack_opcode},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
