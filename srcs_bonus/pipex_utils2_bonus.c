#include "pipex_bonus.h"

char	*strjoin_2times(char *path, const char *str, char *cmd)
{
	char	*tmp_path_cmd;
	char	*path_cmd;

	tmp_path_cmd = ft_strjoin(path, str);
	if (tmp_path_cmd == NULL)
		return (NULL);
	path_cmd = ft_strjoin(tmp_path_cmd, cmd);
	if (path_cmd == NULL)
	{
		free(tmp_path_cmd);
		return (NULL);
	}
	free(tmp_path_cmd);
	return (path_cmd);
}

char	*search_cmd(char *cmd)
{
	char	*path_cmd;
	int		i;

	i = 0;
	while (g_path_list[i] != NULL)
	{
		path_cmd = strjoin_2times(g_path_list[i], "/", cmd);
		if (path_cmd == NULL)
			return (NULL);
		if (access(path_cmd, X_OK) == 0)
			break ;
		free(path_cmd);
		i++;
	}
	if (g_path_list[i] == NULL)
		return (cmd);
	free (cmd);
	return (path_cmd);
}

char	**cmd_sep_2(char **argv, t_data *data)
{
	char	**cmd_c;
	char	*tmp_cmd;

	cmd_c = ft_split(argv[data->index], ' ');
	tmp_cmd = search_cmd(cmd_c[0]);
	if (tmp_cmd == cmd_c[0])
		free_no_cmd(cmd_c[0], cmd_c);
	if (tmp_cmd == NULL)
		free_cmd_path("malloc", cmd_c);
	cmd_c[0] = tmp_cmd;
	return (cmd_c);
}
