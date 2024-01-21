#include "monty.h"

/**
 * strdup_custom - to create a duplicate copy of a string
 * @str: string
 * Return: dup_str
 */

char *strdup_custom(const char *str)
{
	char *dup_str = NULL;
	size_t len;

	if (str == NULL)
		return (NULL);

	len = strlen(str);

	dup_str = malloc(len + 1);

	if (dup_str == NULL)
		return (NULL);

	memcpy(dup_str, str, len);
	dup_str[len] = '\0';

	return (dup_str);
}
