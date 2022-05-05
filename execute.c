#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	if (pid == 0)
	{
		/* execution de la commande */
		UNUSED(cmd);
	}
	else
	{
		wait(&status);
	}
	UNUSED(cmd);
	UNUSED(exec_ret);
	UNUSED(status);
}
