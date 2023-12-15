#include "monty.h"
/**
 * add_new_node - function that adds a new node the head stack
 * @head: first elemt of the stack
 * @n: new_value
 * Return: no return
*/
void add_new_node(stack_t **head, int n)
{
	stack_t *newNode, *temp;

	temp = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = newNode;

	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}

