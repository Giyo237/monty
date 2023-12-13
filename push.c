#include "main.h"
#include <stdlib.h>
/**
  * push - function that pushes to the top of a stck
  *@head: pointer to the pointer of the head of the stack
  *@val:value to be added
  *@line_number:tracker
  */
void push(stack_t **head, int val, unsigned int line_number)
{
	stack_t *new;
	char val_str[12];

	sprintf(val_str, "%d", val);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "ERROR: allocation failed\n");
		exit(EXIT_FAILURE);
	}
	if (val == 0 && strcmp("0", val_str) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new);
		exit(EXIT_FAILURE);
	}

	new->n = val;
	new->prev = NULL;

	if (*head != NULL)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	else
	{
		new->next = NULL;
	}
	*head = new;
}
