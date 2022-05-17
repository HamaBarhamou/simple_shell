#include "main.h"
#include <string.h>

/**
 * _strtok - a function ...
 * @str: the chaine
 * @delim: the chaine
 *
 * Return: 1 or 0
 */

char	*_strtok(char *str, const char *delim)
{
	/* implement your code, see man strtok*/

	return (strtok(str, delim));
}
