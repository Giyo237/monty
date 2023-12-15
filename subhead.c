#include "monty.h"
/**
  *_sub- sustration
  *@head: stack head
  *@line_number: line_number
  *Return: void
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int subme, i;

	temp = *head;
	for (i = 0; temp != NULL; i++)
		temp = temp->next;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(monty.ptr);
		free(monty.line);
		freeme(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	subme = temp->next->n - temp->n;
	temp->next->n = subme;
	*head = temp->next;
	free(temp);
}
