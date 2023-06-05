/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:37:35 by cprojean          #+#    #+#             */
/*   Updated: 2023/06/05 13:54:00 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_tab(char **str);

void	free_cmd(t_cmd *cmd, t_info *global_info)
{
	int	runner;

	runner = 0;
	while (runner < global_info->nb_cmds)
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
		runner++;
	}
	if (global_info->outfilefd != -1)
		close(global_info->outfilefd);
	if (global_info->infilefd != -1)
		close(global_info->infilefd);
	free(cmd);
}

void	open_in_failed(t_cmd *cmd, t_info *global_info)
{
	int	runner;

	runner = 0;
	while (runner < global_info->nb_cmds)
	{
		free(cmd[runner].path);
		free_tab(cmd[runner].cmd);
		free_tab(cmd[runner].path_env);
		close(cmd[runner].fdin);
		runner++;
	}
	free(cmd);
}

void	free_a_bit(t_info *global_info)
{
	if (global_info->outfilefd)
		close(global_info->outfilefd);
	if (global_info->infilefd)
		close(global_info->infilefd);
}

void	free_tab(char **str)
{
	int	runner;

	runner = 0;
	while (str[runner])
	{
		if (str[runner] != NULL)
			free(str[runner]);
		runner++;
	}
	free(str);
}

int	is_slash(char *str)
{
	while (*str)
	{
		if (*str == '/')
			return (1);
		else
			str++;
	}
	return (0);
}
