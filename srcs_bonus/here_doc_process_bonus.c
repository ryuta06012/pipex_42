/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_process_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryuuta <hryuuta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:29:03 by hryuuta           #+#    #+#             */
/*   Updated: 2021/10/15 15:29:04 by hryuuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	second_call_child(int *new_pipefd, t_data *data)
{
	close (new_pipefd[READ]);
	dup2(new_pipefd[WRITE], WRITE);
	close(new_pipefd[WRITE]);
	g_cmd_c = cmd_sep_2(g_argv, data);
	if (execve(g_cmd_c[0], g_cmd_c, NULL) == -1)
		free_cmd_path("execve", g_cmd_c);
}

void	second_call_parent(int	*new_pipefd, pid_t new_pid)
{
	int		flag;

	flag = 0;
	waitpid(new_pid, &flag, 0);
	close(new_pipefd[WRITE]);
	if (dup2(new_pipefd[READ], READ) == -1)
		free_path_list("dup2");
	close(new_pipefd[READ]);
}

void	here_doc_stdout(char **argv, int *pipe_fd, int *index)
{
	char	*line;
	char	*separator;
	int		status;
	int		count;

	close(pipe_fd[READ]);
	count = 0;
	separator = argv[index[NOW] - 1];
	while (1)
	{
		if (count == 0)
			ft_putstr_fd("pipe heredoc> ", 1);
		status = get_next_line(0, &line);
		if (ft_strncmp(line, "LIMITER", 9) == 0)
		{
			free(line);
			line = NULL;
			break ;
		}
		check_status(pipe_fd, status, line);
		if (status == -1)
			free_path_list("malloc");
		count++;
	}
	free_exit(line);
}

void	fd_close_dup2(int *pipe_fd)
{
	if (close(pipe_fd[WRITE]))
		free_path_list("close");
	if (dup2(pipe_fd[READ], READ) == -1)
		free_path_list("dup2");
	if (close(pipe_fd[READ]) == -1)
		free_path_list("close");
}

void	here_doc_process(int *pipe_fd, pid_t id, t_data *data)
{
	int		flag;
	int		new_pipefd[FD_NUM];
	pid_t	new_pid;

	flag = 0;
	waitpid(id, &flag, 0);
	fd_close_dup2(pipe_fd);
	if (pipe(new_pipefd) == -1)
	{
		free_path_list("pipe");
		exit(EX_OSERR);
	}
	new_pid = fork();
	if (new_pid == -1)
	{
		free_path_list("fork");
		exit(EXIT_FAILURE);
	}
	if (new_pid == 0)
		second_call_child(new_pipefd, data);
	else
		second_call_parent(new_pipefd, new_pid);
	data->count = 1;
}
