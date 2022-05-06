#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * shell_1_0 - function
 *@cmd: the command input of user
 *@env: the environment
 *
 *Return: void
 */

void shell_1_0(char *cmd, char **env)
{
	if (_strcmp("env", cmd) == 0)
	{
		int i = 0;

		while (env[i] != NULL)
		{
			_puts(env[i]);
			_putchar('\n');
			i++;
		}
	}
}

/**
 * _executecmd - a function ...
 * @cmd: the chaine
 * @argv: the programme arguments
 *
 * Return: 1 or 0
 */

void	_executecmd(char *cmd, char **argv)
{
	int status;
	pid_t pid = 0;
	int exec_ret = 0;
	char *cmds[] = {"", (char *) 0};
	char *cmdsrc;

	shell_1_0(cmd, argv);

	cmds[0] = cmd;
	cmdsrc = (char *) malloc((_strlen(cmd) + 6) * sizeof(char));
	cmdsrc = _strcat(cmdsrc, "/bin/");
	cmdsrc = _strcat(cmdsrc, cmd);

	pid = fork();

	if (pid < 0)
	{
		perror("Error:");
		return;
	}
	else if (pid == 0)
	{
		/* execution de la commande */
		exec_ret = execve(cmdsrc, cmds, NULL);

		if (exec_ret < 0)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	_puts("($) ");
	UNUSED(cmd);
	UNUSED(exec_ret);
	UNUSED(status);
}
