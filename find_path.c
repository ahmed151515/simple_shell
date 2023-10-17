#include "main.h"
/**
 * StrCon - s1 + s2
 * @s1: string
 * @s2: string
 * Return: s1 + s2
 */
char *StrCon(char *s1, char *s2)
{
	char *res;
	int i = 0, j = 0;

	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0')
	{
		j++;
	}
	res = malloc(i + j + 1);
	if (res == NULL)
	{
		return (NULL);
	}
	res[i + j] = '\0';
	i = 0;
	while (*s1 != '\0')
	{
		res[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		res[i] = *s2;
		i++;
		s2++;
	};
	return (res);
}

/**
 * Find_Path - Find_Path
 * @s: path
 * Return: path
 */
char *Find_Path(char *s)
{
	char *del;

	if (s == NULL)
	{
		return (NULL);
	}

	if (access(s, F_OK) == 0)
	{
		return (s);
	}
	del = s;
	s = StrCon("/bin/", s);
	if (access(s, F_OK) == 0)
	{
		free(del);
		return (s);
	}
	free(del);
	free(s);
	s = NULL;
	return (s);
}
