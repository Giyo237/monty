#include "main.h"
/**
 * _pall - function that prints the stack
 *@head: stack head
 *@counter: unused
 *Return: void
 */
void _pall(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;

	(void) counter;

	if (*head == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
