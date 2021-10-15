/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryuuta <hryuuta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:28:42 by hryuuta           #+#    #+#             */
/*   Updated: 2021/10/15 15:28:43 by hryuuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**g_path_list;
char	**g_cmd_c;

static void	ft_call_child(int *pipe_fd, char **argv, char **envp)
{
	char	**cmd;
	int		open_in_fd;

	close (pipe_fd[0]);
	open_in_fd = open(argv[1], O_RDONLY);
	if (open_in_fd == -1)
		free_path_list("open");
	if (dup2(pipe_fd[1], 1) == -1 || dup2(open_in_fd, 0) == -1)
		free_path_list("dup2");
	cmd = cmd_sep_2(argv);
	if (execve(cmd[0], cmd, envp) == -1)
		free_cmd_path("execve", cmd);
}

static void	ft_call_parent(int *pipe_fd, char **argv, char **envp)
{
	char	**cmd;
	int		open_out_fd;

	open_out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, \
	S_IREAD | S_IWRITE);
	wait(0);
	close(pipe_fd[1]);
	if (open_out_fd == -1)
		free_path_list("open");
	if (access(argv[4], W_OK) == -1)
		free_path_list(argv[4]);
	if (dup2(pipe_fd[0], 0) == -1 || dup2(open_out_fd, 1) == -1)
		free_path_list("dup2");
	close(pipe_fd[0]);
	cmd = cmd_sep_3(argv);
	if (execve(cmd[0], cmd, envp) == -1)
		free_cmd_path("execve", cmd);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	access_check(argc, argv, envp);
	if (pipe(pipefd) == -1)
	{
		free_path_list("pipe");
		exit(EX_OSERR);
	}
	pid = fork();
	if (pid == -1)
	{
		free_path_list("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		ft_call_child(pipefd, argv, envp);
	else
		ft_call_parent(pipefd, argv, envp);
	free_array(g_path_list);
	return (0);
}
