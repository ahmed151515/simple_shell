#include "main.h"
/**
 * main - main
 * @ac: num of arg
 * @av: arg
 * @env:fdf
 * Return: int
 */
int main(int ac, char *av[], char *env[])
{
	char *s = NULL;
	char **cmd = NULL;
	size_t len = 0;
	int id;

	(void)ac;
	while (1)
	{
		if (getline(&s, &len, stdin) == -1)
			break;
		if (check_continu(s, env))
		{
			continue;
		}
		if (s[0] == '\n' || is_spase_line(s))
			continue;
		cmd = SetCmd(s);
		cmd[0] = Find_Path(cmd[0]);
		if (cmd[0] == NULL)
		{
			free_cmd(cmd);
			perror(av[0]);
			continue;
		}
		id = fork();
		if (id != 0)
			wait(NULL);
		if (id  == 0)
		{
			execve(cmd[0], cmd, NULL);
			perror(av[0]);
			return (0);
		}
		free_cmd(cmd);
	}
	free(s);
	return (0);
}
