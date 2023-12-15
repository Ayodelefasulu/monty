#include "monty.h"

/**
 * _isinteger - Checks if a string represents an integer.
 * @str: String to check.
 * Return: 1 if it's an integer, 0 otherwise.
 */
int _isinteger(char *str)
{
	if (*str == '-')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
