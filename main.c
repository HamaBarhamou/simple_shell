#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <stdio.h>


/**
 * main - check the code
 *@argc: the number of the argument
 *@argv: the argument list of the table
 *@env:  the variable of the environement
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	/**
	*while (env[i] != NULL)
	*{
	*	printf("env: %s\n",env[i]);
	*	i++;
	*}
	*/

	_puts("($) ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		line[_strlen(line) - 1] = '\0';
		_puts("($) ");
		if (_strcmp("exit", line) == 0)
		{
			free(line);
			exit(0);
		}
		_executecmd(line, argc, argv, env);
	}

	if (line)
		free(line);

	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);
	UNUSED(i);
	return (0);
}
