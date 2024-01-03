#include "monty.h"

/**
 * main - read opcode from monty file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;

	/* Check if there is only one argument */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Check if file can be opened */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read each line of file */
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		/* Check if line is empty */
		if (strcmp(line, "\n") == 0)
			continue;
		opcode = strtok(line, " \n\t\r");
		/* Check if line is a comment */
		if (opcode != NULL && opcode[0] != '#')
			getopcode(opcode, line_number, line, file);
	}
	freeArg(&stack, line, file);
	exit(EXIT_SUCCESS);
}
