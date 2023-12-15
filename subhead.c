#include "monty.h"
/**
 * _sub - function that subs the head with other elements
 *@head:pointer to the pointer of th head of the stcck
 *line_number:line_number
 *Return:void
 */
void _sub(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr,"L%d: can't sub, staack too short\n", line_number);
		freeme(*head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	_pop(head, line_number);
}
