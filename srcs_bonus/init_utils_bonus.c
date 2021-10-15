/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryuuta <hryuuta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:28:56 by hryuuta           #+#    #+#             */
/*   Updated: 2021/10/15 15:28:57 by hryuuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
