/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryuuta <hryuuta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:28:11 by hryuuta           #+#    #+#             */
/*   Updated: 2021/10/15 15:28:12 by hryuuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sysexits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

extern char	**g_path_list;
/*pipex_utils1.c*/
char	**search_path(char **envp);
void	access_check(int argc, char **argv, char **envp);
/*pipex_utils2.c*/
char	*strjoin_2times(char *path, const char *str, char *cmd);
char	*search_cmd(char *cmd);
char	**cmd_sep_2(char **argv);
char	**cmd_sep_3(char **argv);
/*free_utils.c*/
void	free_array(char **array);
void	free_path_list(char *str);
void	free_cmd_path(char *str, char **cmd);
void	free_no_cmd(char *str, char **cmd);

#endif
