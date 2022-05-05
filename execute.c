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
	int status = 0;
	pid_t pid = 0;
	int exec_ret = 0;

	pid = fork();
	if (pid == 0)
	{
		UNUSED(cmd);
	}
	else if (pid > 0)
	{
		UNUSED(cmd);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	UNUSED(cmd);
	UNUSED(exec_ret);
	UNUSED(status);
}
