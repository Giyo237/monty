#include <stdio.h>
#include "monty.h"
#include <stdlib.h>

monty_t monty = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line;
	FILE *ptr;
	size_t s = 0;
	ssize_t rline = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ptr = fopen(argv[1], "r");
	monty.ptr = ptr;
	if (!ptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rline > 0)
	{
		line = NULL;
		rline = getline(&line, &s, ptr);
		monty.line = line;
		line_number++;
		if (rline > 0)
		{
			execute(line, &stack, line_number, ptr);
		}
		free(line);
	}
	freeme(stack);
	fclose(ptr);
return (0);
}
