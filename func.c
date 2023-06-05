#include "monty.h"
#include <stdio.h>

/**
 * open_file - function to open monty files
 * filename: pointer to the file to be opened
 * Return: void
 */
void open_file(char *filename)
{
	FILE *fptr;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	read_file(fptr);
	fclose(fptr);
}

void read_file(FILE *fptr)
{
	char *buf;
	int len = 50;
	int line;

	buf = malloc(sizeof(char)*len);
	for (line = 1; fgets(buf, len, fptr); line++)
		separate(line, buf);
	free(buf);
	printf("Still working?");
}

void separate(int line, char *text)
{
	char *opcode, *val;
	functions func;
	stack_t *head;

	printf("Here works fine too");
	opcode = strtok(text, " $");
	val = strtok(NULL, " $");
	
	printf("%s", val);
	func = check_func(opcode);
	func(&head, line);
}

functions check_func(char *opcode)
{
	int i;

	instruction_t functions[] = {
		{"push", push_to_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};

	for (i = 0; functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
			return (functions[i].f);
	}
	return (NULL);
}
