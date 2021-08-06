#include "pipex_bonus.h"

char	**search_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0 && envp[i])
		i++;
	if (envp[i] == NULL)
		exit(1);
	path = ft_split(&envp[i][5], ':');
	if (path == NULL)
	{
		perror("malloc");
		exit(1);
	}
	return (path);
}

void	here_doc_not(int ac, char **av, t_data *data)
{
	if (access(av[1], R_OK) == -1)
		free_path_list(av[1]);
	else
	{
		data->in_fd = open(av[1], O_RDONLY);
		if (data->in_fd == -1)
			free_path_list("open");
	}
	if (access(av[ac - 1], W_OK) == -1 && access(av[ac - 1], F_OK) == 0)
		free_path_list(av[ac - 1]);
	else
	{
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, \
		S_IREAD | S_IWRITE);
		if (data->out_fd == -1)
			free_path_list("open");
	}
}

void	here_doc_exist(int ac, char **av, t_data *data)
{
	if (access(av[ac - 1], W_OK) == -1 && access(av[ac - 1], F_OK) == 0)
		free_path_list(av[ac - 1]);
	else
	{
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, \
		S_IREAD | S_IWRITE);
		if (data->out_fd == -1)
			free_path_list("open");
	}
}

void	access_check(int ac, char **av, t_data *data, int *index)
{
	g_argv = av;
	if (index[HERE_DOC] == 0)
		here_doc_not(ac, av, data);
	else
		here_doc_exist(ac, av, data);
}

void	index_set(int argc, char **argv, int *index)
{
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		index[NOW] = 2;
		index[START] = 2;
		index[STOP] = argc - 2;
		index[HERE_DOC] = 0;
	}
	else
	{
		index[NOW] = 3;
		index[START] = 3;
		index[STOP] = argc - 2;
		index[HERE_DOC] = 1;
	}
}
