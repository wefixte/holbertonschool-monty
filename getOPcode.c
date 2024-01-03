#include "monty.h"

stack_t *stack = NULL;

/**
 * getopcode - get opcode from line
 * @opcode: opcode from line of file
 * @line: line from file
 * @line_number: line number
 * @file: file
 * Return: void
*/

void getopcode(char *opcode, unsigned int line_number, char *line, FILE *file)
{
	size_t index;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	/* Check if opcode is valid */
	for (index = 0; opcodes[index].opcode != NULL; index++)
	{
		/* Compare opcode with line */
		if (strcmp(opcodes[index].opcode, opcode) == 0)
		{
			/* Execute function depending on opcode */
			opcodes[index].f(&stack, line_number);
			break;
		}
	}

	/* Check if opcode is not valid */
	if (opcodes[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
		/* TODO : function to free */
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
