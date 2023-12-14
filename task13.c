#include "monty.h"
/**
 * cyp_rotl_opcode - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void cyp_rotl_opcode(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *cyp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	cyp = (*head)->next;
	cyp->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = cyp;
}
