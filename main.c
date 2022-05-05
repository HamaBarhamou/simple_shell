#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define Buff_Size 1024

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int cpt = 0, i = 0;


	_puts("($) ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		line[_strlen(line) - 1] = '\0';

		_puts("($) ");
		if (_strcmp("exit", line) == 0)
		{
			free(line);
			for (i = 0; i < cpt; i++)
				exit(0);
		}
		

		_executecmd(line);
		cpt++;
	}

	if (line)
		free(line);

	return (0);
}
