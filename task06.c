#include "monty.h"
/**
 * sub_opcode - subtracts the top element of the stack
 * from the second top element of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void sub_opcode(stack_t **head, unsigned int counter)
{
	stack_t *cyp;
	int sus, nodes;

	cyp = *head;
	for (nodes = 0; cyp != NULL; nodes++)
		cyp = cyp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	cyp = *head;
	sus = cyp->next->n - cyp->n;
	cyp->next->n = sus;
	*head = cyp->next;
	free(cyp);
}
