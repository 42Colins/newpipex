/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:27:55 by cprojean          #+#    #+#             */
/*   Updated: 2023/06/05 13:54:29 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_on_error(t_info *global_info, t_cmd *cmd, int index)
{
	int	runner;

	(void) index;
	runner = 0;
	while (runner < global_info->nb_cmds)
	{
		if(runner != index)
		{
			if (cmd[runner].cmd[0] == cmd[runner].path)
				free_tab(cmd[runner].cmd);
			else
			{
				free_tab(cmd[runner].cmd);
				free(cmd[runner].path);
			}
			free_tab(cmd[runner].path_env);
			close(cmd[runner].fdin);
		}
		runner++;
	}
	if (global_info->outfilefd != -1)
		close(global_info->outfilefd);
	if (global_info->infilefd != -1)
		close(global_info->infilefd);
}

void	double_close(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}