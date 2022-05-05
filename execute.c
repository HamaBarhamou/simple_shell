#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _executecmd - a function ...
 * @cmd: the chaine
 *
 * Return: 1 or 0
 */

void	_executecmd(char *cmd)
{
	int status;
	pid_t pid = 0;
	int exec_ret = 0;
	char *cmds[] = {"ls", (char *) 0};

	pid = fork();

	if (pid < 0)
	{
		perror("Error:");
		return;
	}
	else if (pid == 0)
	{
		/* execution de la commande */
		exec_ret = execve("/bin/ls", cmds, NULL);

		if (exec_ret < 0)
		{
			perror("execve a echoue");
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
