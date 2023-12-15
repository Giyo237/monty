#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: void
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int l = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(monty.ptr);
		free(monty.line);
		freeme(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
