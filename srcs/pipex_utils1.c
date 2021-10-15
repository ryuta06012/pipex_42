/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryuuta <hryuuta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:28:28 by hryuuta           #+#    #+#             */
/*   Updated: 2021/10/15 15:28:29 by hryuuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	access_check(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putendl_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EX_USAGE);
	}
	g_path_list = search_path(envp);
	if (access(argv[1], R_OK) == -1)
		free_path_list(argv[1]);
	if (access(argv[4], W_OK) == -1 && access(argv[4], F_OK) == 0)
		free_path_list(argv[4]);
}
