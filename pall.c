#include "monty.h"

/**
* pall - print all elements of the stack
* @stack: stack
* @line_number: line number
* Return: void
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
