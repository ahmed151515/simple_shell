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
/**
 * is_spase_line - is_spase_line
 * @s: string
 * Return: 1 or 0
 */
int is_spase_line(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * check_continu - check
 * @s: ff
 * @env: fff
 * Return: 1 or 0
 */
int check_continu(char *s, char *env[])
{
	int i = 0;

	if (s == NULL)
	{
		return (1);
	}
	if (combar(s, "exit\n"))
	{
		free(s);
		exit(0);
	}
	if (combar(s, "env\n"))
	{
		while (env[i] != NULL)
		{
			printf("%s",env[i]);
			i++;
		}
		return (1);
	}
	return (0);
}
