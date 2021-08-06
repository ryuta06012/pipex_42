#include "pipex_bonus.h"

char	**g_path_list;
char	**g_cmd_c;
char	**g_argv;

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		index[INDEX_NUM];

	g_path_list = search_path(envp);
	init_data(&data, argv);
	index_set(argc, argv, index);
	access_check(argc, argv, &data, index);
	dup2(data.in_fd, 0);
	parent_child_process(argv, &data, index);
	free_array(g_path_list);
	return (0);
}
