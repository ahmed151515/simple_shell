#include "main.h"

/**
 * main - main
 * @ac: num of arg
 * @av: arg
 * Return: int
 */
int main(int ac, char *av[])
{
	char *s = NULL;
	char **cmd = NULL;
	size_t len = 0;
	int id;

	(void)ac;
	while (1)
	{
		printf("$ ");
		if (getline(&s, &len, stdin) == -1)
			break;
		if (combar(s, "exit\n"))
		{
			free(s);
			exit(0);
		}
		if (s[0] == '\n')
			continue;
		cmd = SetCmd(s);
		cmd[0] = Find_Path(cmd[0]);
		if (cmd[0] == NULL)
		{
			free_cmd(cmd);
			printf("%s: No such file or directory\n", av[0]);
			continue;
		}
		id = fork();
		if (id != 0)
			wait(NULL);
		if (id  == 0)
		{
			execve(cmd[0], cmd, NULL);
			printf("%s: No such file or directory\n", av[0]);
			return (0);
		}
		free_cmd(cmd);
	}
	free(s);
	printf("\n");
	return (0);
}