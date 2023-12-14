#include "monty.h"
/**
* freeme - frees a dll
* @head: first elemt of the stack
*/
void freeme(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
