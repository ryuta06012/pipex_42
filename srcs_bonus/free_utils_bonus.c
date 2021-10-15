/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryuuta <hryuuta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:28:53 by hryuuta           #+#    #+#             */
/*   Updated: 2021/10/15 15:28:59 by hryuuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_path_list(char *str)
{
	perror(str);
	free_array(g_path_list);
	exit(EXIT_FAILURE);
}

void	free_cmd_path(char *str, char **cmd)
{
	perror(str);
	free_array(g_path_list);
	if (cmd == NULL)
		free_array(g_cmd_c);
	else
		free_array(cmd);
	exit(EXIT_FAILURE);
}

void	free_no_cmd(char *str, char **cmd)
{
	perror(str);
	free_array(g_path_list);
	free_array(cmd);
	exit(127);
}

void	free_exit(char *line)
{
	free_array(g_path_list);
	free(line);
	line = NULL;
	exit(0);
}
