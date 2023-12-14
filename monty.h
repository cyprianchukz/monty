#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_opcode(stack_t **head, unsigned int counter);
void pall_opcode(stack_t **head, unsigned int counter);
void pint_opcode(stack_t **head, unsigned int counter);
void pop_opcode(stack_t **head, unsigned int counter);
void swap_opcode(stack_t **head, unsigned int counter);
void add_opcode(stack_t **head, unsigned int counter);
void nop_opcode(stack_t **head, unsigned int counter);
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file);
void sub_opcode(stack_t **head, unsigned int counter);
void div_opcode(stack_t **head, unsigned int counter);
void mul_opcode(stack_t **head, unsigned int counter);
void cyp_pchar_opcode(stack_t **head, unsigned int counter);
void cyp_pstr_opcode(stack_t **head, unsigned int counter);
void cyp_rotl_opcode(stack_t **head,  __attribute__((unused)) unsigned int counter);
void cyp_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void cyp_stack_opcode(stack_t **head, unsigned int counter);
void cyp_queue_opcode(stack_t **head, int n);
void cyp_add_node(stack_t **head, int n);
void free_stack(stack_t *head);
void mod_opcode(stack_t **head, unsigned int counter);
void queue_opcode(stack_t **head, unsigned int counter);

#endif
