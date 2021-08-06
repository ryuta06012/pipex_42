#include "pipex_bonus.h"

void	init_data(t_data *data, char **argv)
{
	data->out_fd = 0;
	data->in_fd = 0;
	if (ft_strncmp(argv[1], "here_doc", 10) != 0)
		data->index = 2;
	else
		data->index = 3;
	data->count = 0;
}
