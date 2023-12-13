#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	stack_t *head = NULL, *current, *tmp;

	push(&head, 5, 1);
	push(&head, 10, 2);
	push(&head, 8, 3);

	_pall(&head, 0);

	current = head;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	return (0);
}
