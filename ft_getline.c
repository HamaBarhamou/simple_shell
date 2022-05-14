#include "main.h"

/**
 * _getline - a function ...
 * @lineptr: the chaine
 * @n: the number
 * @stream: the File
 *
 * Return: 1 or 0
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	/* implement your code, see man strtok*/

	UNUSED(lineptr);
	UNUSED(n);
	UNUSED(stream);

	return (getline(lineptr, n, stream));
}
