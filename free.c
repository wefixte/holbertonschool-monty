#include "monty.h"

/**
 * freeArg - function that free arguments
 * @stack: stack
 * @line: line
 * @file: file
*/
void freeArg(stack_t **stack, char *line, FILE *file)
{
	fclose(file);
	free(line);
	freeStack(stack);
}

/**
 * freeStack - Frees the memory used by the stack.
 * @stack: Pointer to the top of the stack.
 */
void freeStack(stack_t **stack)
{
	stack_t *current = *stack, *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
