/*****************************************************************************/
/*                                                                           */
/*                                               _____  ______    ____  ___  */
/* add_nodeinstruction_end.c                    /  _  \ |    |    \   \/  /  */
/*                                             /  /_\  \|    |     \     /   */
/* By: Barahmou   <hamabarhamou@gmail.com>    /    |    \    |___  /     \   */
/*                                            \____|__  /_______ \/___/\  \  */
/* Created: 2022-03-28 09:44:03   $Barahmou           \/        \/      \_/  */
/* Updated: 2022-03-28 09:44:03 by Barahmou                                  */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>


/**
 * add_nodeinstruction_end - a function ...
 * @head: the list
 * @str: the chaine
 *
 * Return: 1 or 0
 */

instruction_l *add_nodeinstruction_end(instruction_l **head, char *str)
{
	instruction_l *new, *ptr = *head;

	new =  malloc(sizeof(instruction_l));
	/*new->str = malloc(sizeof(char) * _strlen(str));*/
	new->str = strdup(str);

	if (new == NULL)
		return (NULL);

	new->str = str;
	new->next = NULL;

	if (ptr == NULL)
	{
		*head = new;
		return (*head);
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	return (new);
}

