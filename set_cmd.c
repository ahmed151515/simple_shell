#include "main.h"
/**
 * StrCopy - copy text from s to s2
 * @s: string
 * Return: pointer
 */
char *StrCopy(char *s)
{
	int i, len;
	char *copy;

	if (s == NULL)
	{
		return (NULL);
	}
	for (len = 0; s[len] != '\0'; len++)
		;
	copy = malloc(len + 1);
	if (copy == NULL)
	{
		return (NULL);
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		copy[i] = s[i];
	}

	copy[i] = '\0';

	return (copy);
}
/**
 * SetCmd - spilt commands
 * @s: string
 * Return: string
 */
char **SetCmd(char *s)
{
	char *s2;
	char *deilm = " \n";
	char *tok;
	char **cmd;
	int i = 0;

	if (s == NULL)
	{
		return (NULL);
	}
	s2 = StrCopy(s);

	tok = strtok(s, deilm);
	while (tok != NULL)
	{
		tok = strtok(NULL, deilm);
		i++;
	}
	cmd = malloc(sizeof(char *) * (i + 1));
	if (cmd == NULL)
	{
		return (NULL);
	}
	i = 0;
	tok = strtok(s2, deilm);
	while (tok != NULL)
	{
		cmd[i] = StrCopy(tok);
		tok = strtok(NULL, deilm);
		i++;
	}
	cmd[i] = NULL;
	free(s2);
	return (cmd);
}
