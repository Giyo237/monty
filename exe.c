#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_number: line_counter
* @ptr: poiner to monty file
* @line: line content
* Return: no return
*/
int execute(char *line, stack_t **stack, unsigned int line_number, FILE *ptr)
{
	instruction_t opst[] = {
				{"push", push}, {"pall", _pall},
				{"pint", _pint}, {"pop", _pop},
				{"swap", _swap}, {"add", _add},
				{"nop",_nop}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	monty.val = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(ptr);
		free(line);
		freeme(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
