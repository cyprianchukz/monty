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
void queue_opcode(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: queue integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: queue integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		cyp_add_node(head, n);
	else
		queue_opcode(head, counter);
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
