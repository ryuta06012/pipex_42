/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryuuta <hryuuta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:27:55 by hryuuta           #+#    #+#             */
/*   Updated: 2021/10/15 15:27:57 by hryuuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sysexits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include "libft.h"
# include "get_next_line.h"

extern char	**g_path_list;
extern char	**g_cmd_c;
extern char	**g_argv;

typedef struct s_data
{
	int	out_fd;
	int	in_fd;
	int	index;
	int	count;
}				t_data;

enum	e_fd
{
	READ,
	WRITE,
	FD_NUM
};

enum	e_index
{
	NOW,
	START,
	STOP,
	HERE_DOC,
	INDEX_NUM
};

/*pipex_bonus.c*/
void	ft_call_child(int *pipe_fd, char **argv, t_data *data, int *index);
void	ft_call_parent(int *pipe_fd, pid_t id, t_data *data, int *index);
/*pipex_bonus_utils1.c*/
char	**search_path(char **envp);
void	here_doc_not(int ac, char **av, t_data *data);
void	here_doc_exist(int ac, char **av, t_data *data);
void	access_check(int ac, char **av, t_data *data, int *index);
void	index_set(int argc, char **argv, int *index);
/*pipex_bonus_utils2.c*/
char	*strjoin_2times(char *path, const char *str, char *cmd);
char	*search_cmd(char *cmd);
char	**cmd_sep_2(char **argv, t_data *data);
char	**cmd_sep_3(char **argv);
void	check_status(int *pipe_fd, int status, char *line);
/*free_bonus_utils.c*/
void	free_array(char **array);
void	free_path_list(char *str);
void	free_cmd_path(char *str, char **cmd);
void	free_no_cmd(char *str, char **cmd);
void	free_exit(char *line);
/*init_utils.c*/
void	init_data(t_data *data, char **argv);
/*first_process_bonus.c*/
void	ft_putstr_endl(char *line, int *pipe_fd);
void	parent_child_process(char **argv, t_data *data, int *index);
void	ft_call_child(int *pipe_fd, char **argv, t_data *data, int *index);
void	ft_call_parent(int *pipe_fd, pid_t id, t_data *data, int *index);
/*here_doc_process*/
void	here_doc_stdout(char **argv, int *pipe_fd, int *index);
void	here_doc_process(int *pipe_fd, pid_t id, t_data *data);
void	fd_close_dup2(int *pipe_fd);
void	second_call_child(int *new_pipefd, t_data *data);
void	second_call_parent(int	*new_pipefd, pid_t new_pid);

#endif