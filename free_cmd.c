#include "main.h"

/**
 * free_cmd - free_cmd
 * @cmd: cmd
 */
void free_cmd(char **cmd)
{
	int i;

	for (i = 0; cmd[i] != NULL; i++)
	{
		free(cmd[i]);
	}
	free(cmd[i]);
	free(cmd);
}
