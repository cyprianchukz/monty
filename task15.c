#include "monty.h"
/**
 * cyp_stack_opcode - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void cyp_stack_opcode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

#include "monty.h"
/**
 * cyp_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void cyp_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * cyp_queue_opcode - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void cyp_queue_opcode(stack_t **head, int n)
{
	stack_t *new_node, *cyp;

	cyp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (cyp)
	{
		while (cyp->next)
			cyp = cyp->next;
	}
	if (!cyp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		cyp->next = new_node;
		new_node->prev = cyp;
	}
}
