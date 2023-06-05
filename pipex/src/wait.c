/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:28:53 by cprojean          #+#    #+#             */
/*   Updated: 2023/06/05 09:24:49 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	wait_all(t_cmd *cmd, t_info *global_info)
{
	int	runner;

	runner = 0;
	while (runner < global_info->nb_cmds)
	{
		waitpid(cmd[runner].pid, NULL, 0);
		runner++;
	}
}

void	free_split(char **str)
{
	int	runner;

	runner = 0;
	while (str[runner])
		free(str[runner++]);
	free(str);
}

void	ft_error(char *s1)
{
	s1 = ft_strjoin(s1, "\n");
	ft_putstr_fd(s1, 2);
	free(s1);
}

void	ft_error2(char *s1, char *s2)
{
	s1 = ft_strjoin(s1, s2);
	s1 = ft_strjoin2(s1, "\n");
	ft_putstr_fd(s1, 2);
	free(s1);
}

int	close_fds(t_cmd *cmd, t_info *global_info, int *fd)
{
	close(cmd->fdin);
	if (global_info->infilefd != -1)
		close(global_info->infilefd);
	if (global_info->outfilefd != -1)
		close(global_info->outfilefd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
