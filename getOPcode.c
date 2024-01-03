#include "monty.h"

/**
 * getopcode - get opcode from line
 * @line: line from file
 * @line_number: line number
 * @file: file
 * Return: void
*/

void getopcode(char *line, unsigned int line_number, FILE *file)
{
	int index;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		/**
		 * {"pint", pint},
		 * {"pop", pop},
		 * {"swap", swap},
		 * {"add", add},
		 * {"nop", nop},
		 * {NULL, NULL}
		*/
	};

	/* Check if opcode is valid */
	for (index = 0; opcodes[index].opcode != NULL; index++)
	{
		/* Compare opcode with line */
		if (strcmp(line, opcodes[index].opcode) == 0)
		{
			/* Execute function depending on opcode */
			opcodes[index].f(&stack, line_number);
			return;
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
