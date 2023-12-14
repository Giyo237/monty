#include "monty.h"
/**
 * _queue - prints the top
 * @head: pointer to the pointer of the stack head
 * @line_number: line_number
 * Return: void
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	monty.i = 1;
}

/**
 * add_queue_element - function that adds elemt to the tail
 * @new: newnode to be added
 * @head: head of the stack
 * Return: void
 */
void add_queue_element(stack_t **head, int n)
{
	stack_t *newNode, *temp;

	temp = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("allocation error\n");
	}
	newNode->n = n;
	newNode->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		temp->next = newNode;
		newNode->prev = temp;
	}
}
