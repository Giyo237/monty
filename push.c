#include "monty.h"
#include <stdlib.h>
/**
  * push - function that pushes to the top of a stck
  *@head: pointer to the pointer of the head of the stack
  *@val:value to be added
  *@line_number:tracker
  */
void push(stack_t **head, unsigned int line_number)
{
	int n, a = 0, v = 0;

if (monty.val)
	{
		if (monty.val[0] == '-')
			a++;
		for (; monty.val[a] != '\0'; a++)
		{
			if (monty.val[a] > 57 || monty.val[a] < 48)
				v = 1; }
		if (v == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(monty.ptr);
			free(monty.line);
			freeme(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n",line_number);
		fclose(monty.ptr);
		free(monty.line);
		freeme(*head);
		exit(EXIT_FAILURE); }
	n = atoi(monty.val);
	if (monty.i == 0)
		add_new_node(head, n);
	else
		add_queue_element(head, n);
}
