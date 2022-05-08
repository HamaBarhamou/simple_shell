#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <stdio.h>

/**
 * _arguments - a function
 * @str: the chaine of the caractere
 * @arglist: the list of list argument
 * Return: the chaine
 */

char **_arguments(char *str, char **arglist)
{
	char *cmd = strdup(str);
	char *arg;
	const char *separator = " ";
	int i = 0;

	arg = strtok(cmd, separator);
	while (arg != NULL)
	{
		arglist[i] = strdup(arg);
		i++;
		arg = strtok(NULL, separator);
	}
	arglist[i] = NULL;
	free(cmd);
	return (arglist);
}

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
	char *arg_list[MAX_LINE];

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
		_executecmd(_arguments(line, arg_list), argc, argv, env);
	}

	if (line)
		free(line);

	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);
	UNUSED(i);
	UNUSED(arg_list);
	return (0);
}
