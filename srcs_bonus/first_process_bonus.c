#include "pipex_bonus.h"

void	ft_putstr_endl(char *line, int *pipe_fd)
{
	ft_putstr_fd("pipe heredoc> ", 1);
	ft_putendl_fd(line, pipe_fd[WRITE]);
}

void	ft_call_child(int *pipe_fd, char **argv, t_data *data, int *index)
{
	if (index[HERE_DOC] == 1 && data->index == index[START] && data->count == 0)
		here_doc_stdout(argv, pipe_fd, index);
	else
	{
		close (pipe_fd[READ]);
		if (data->index != index[STOP])
			dup2(pipe_fd[WRITE], WRITE);
		else
			dup2(data->out_fd, 1);
		close(pipe_fd[WRITE]);
		g_cmd_c = cmd_sep_2(argv, data);
		if (execve(g_cmd_c[0], g_cmd_c, NULL) == -1)
			free_cmd_path("execve", NULL);
	}
}

void	ft_call_parent(int *pipe_fd, pid_t id, t_data *data, int *index)
{
	int	flag;

	if (index[HERE_DOC] == 1 && data->index == index[START] && data->count == 0)
		here_doc_process(pipe_fd, id, data);
	else
	{
		waitpid(id, &flag, 0);
		close(pipe_fd[WRITE]);
		if (dup2(pipe_fd[READ], READ) == -1)
			free_path_list("dup2");
		free_array(g_cmd_c);
		close(pipe_fd[READ]);
	}
}

void	parent_child_process(char **argv, t_data *data, int *index)
{
	int	pipefd[FD_NUM];
	int	pid;

	while (index[START] <= index[STOP])
	{
		if (pipe(pipefd) == -1)
		{
			free_path_list("pipe");
			exit(EX_OSERR);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			ft_call_child(pipefd, argv, data, index);
		else
			ft_call_parent(pipefd, pid, data, index);
		data->index++;
		index[START]++;
	}
}
