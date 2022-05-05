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
	ssize_t r;
	char *buff;

	while (r)
	{
		_puts("($) ");
		buff = malloc(sizeof(char) * Buff_Size + 1);
		r = read(1, buff, Buff_Size);
		buff[_strlen(buff) - 1] = '\0';

		if (_strcmp("exit", buff) == 0)
		{
			free(buff);
			exit(0);
		}

		_executecmd(buff);
		/*_puts(buff);*/
	}
	return (0);
}
