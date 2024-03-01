#include "main.h"

/**
 * _strlen - gets the length lf the string
 * @s: parameter is the variable that hold the string
 * Return: length of string
 */

int _strlen(char *s)
{
	int c = 0;

	while (*s != '\0')
	{
		c++;
		s++;
	}

	return (c);
}

/**
 * _strcmp - program to compare two strings
 * @s1: first argument - takes string to be compared
 * @s2: second argument - takes string to be compared with
 * Return: Returns the value of the compared string in decimal
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * _strcspsn - searches a character in a string and returns the index
 * @source: string to be searched
 * @s: character to search
 * Return: index of character at position i;
 **/

int _strcspsn(char *source, char s)
{
	int i = 0;

	while (source[i] != '\0')
	{
		if (source[i] != s)
			i++;
	}

	return (i);
}
