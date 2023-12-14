#include "monty.h"
/**
 * mul_opcode - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void mul_opcode(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, cyp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	cyp = h->next->n * h->n;
	h->next->n = cyp;
	*head = h->next;
	free(h);
}
