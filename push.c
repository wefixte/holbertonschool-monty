#include "monty.h"

/**
* push - push an element to the stack
* @stack: stack
* @line_number: line number
* Return: void
*/

void push(stack_t **stack, unsigned int line_number)
{
	int num;
	char *token, *endptr;
	stack_t *newNode;

	token = strtok(NULL, " \t\n\r");

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = strtol(token, &endptr, 10);

	if (*endptr != '\0')
	{
		/*bloque à cette ligne*/
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = num;
	newNode->prev = NULL;

	if (*stack == NULL)
		newNode->next = NULL;
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
