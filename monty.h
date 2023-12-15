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
 * struct monty_s - variables -args, file, line content
 * @val: value
 * @ptr: pointer to monty file
 * @line: line content
 * @i: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct monty_s
{
	char *val;
	FILE *ptr;
	char *line;
	int i;
}  monty_t;
extern monty_t monty;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int counter);
void add_new_node(stack_t **head, int new);
void add_queue_element(stack_t **head, int new);
void _queue(stack_t **head, unsigned int line_number);
void freeme(stack_t *head);
int execute(char *line, stack_t **stack, unsigned int line_number, FILE *ptr);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);

#endif
