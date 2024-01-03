#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}
