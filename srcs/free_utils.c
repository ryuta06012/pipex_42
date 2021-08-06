#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_path_list(char *str)
{
	perror(str);
	free_array(g_path_list);
	exit(EXIT_FAILURE);
}

void	free_cmd_path(char *str, char **cmd)
{
	perror(str);
	free_array(g_path_list);
	free_array(cmd);
	exit(EXIT_FAILURE);
}

void	free_no_cmd(char *str, char **cmd)
{
	perror(str);
	free_array(g_path_list);
	free_array(cmd);
	exit(127);
}
