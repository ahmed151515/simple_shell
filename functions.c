#include "main.h"


/**
 * combar - combar
 * @s1: s
 * @s2: s
 * Return: 1 if  s1 == s2
 */
int combar(char *s1, char *s2)
{
	int i = 0, j = 0;

	for (; s1[i] != '\0'; i++)
		;
	for (; s2[j] != '\0'; j++)
		;
	if (i != j)
	{
		return (0);
	}
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[j])
		{
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}
