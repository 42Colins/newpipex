/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:29:41 by cprojean          #+#    #+#             */
/*   Updated: 2023/06/04 17:57:42 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int		cmd_exec(t_cmd *cmd, int runner, t_info global_info, int *fd);
int		dup_in(t_cmd cmd, t_info global_info, int runner);
int		dup_out(t_info global_info, int runner, int *fd);
void	free_tab(char **str);
int		close_fds(t_cmd *cmd, t_info *global_info, int *fd);

void	do_exec(t_cmd *cmd, t_info *global_info)
{
	int	runner;
	int	fd[2];

	runner = 0;
	while (runner < global_info->nb_cmds)
	{
		if (pipe(fd) == -1)
			exit(1);
		cmd[runner].pid = fork();
		if (cmd[runner].pid == -1)
			return ;
		if (cmd[runner].pid == 0)
		{
			if_child(cmd[runner], global_info, runner);
		}
		else
		{
			if (runner + 1 < global_info->nb_cmds)
				cmd[runner + 1].fdin = fd[0];
			close(fd[1]);
		}
		runner++;
	}
	close(fd[0]);
}

void	if_child(t_cmd cmd, t_info global_info, int runner)
{
	if (runner == 0)
	{
		global_info->infilefd = open(global_info->infile, O_RDONLY);
		if (global_info->infilefd == -1)
			return (ft_error(strerror(errno)), \
			open_in_failed(cmd, global_info), exit(1));
		cmd[0].fdin = global_info->infilefd;
	}
	else if (runner + 1 == global_info->nb_cmds)
	{
		global_info->outfilefd = open(global_info->outfile, \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (global_info->outfilefd == -1)
			return (ft_error(strerror(errno)), \
			free_cmd(cmd, global_info), exit(1));
	}
	if (cmd_exec(&cmd[runner], runner, *global_info, fd) != 0)
		return (free_cmd(cmd, global_info), exit(1));
}

int	cmd_exec(t_cmd *cmd, int runner, t_info global_info, int *fd)
{
	if (dup_in(*cmd, global_info, runner) != 0)
		return (ft_putstr_fd(strerror(errno), 2), -1);
	if (dup_out(global_info, runner, fd) != 0)
		return (ft_putstr_fd(strerror(errno), 2), -1);
	close_fds(cmd, &global_info, fd);
	if (cmd->path == NULL)
		return (ft_error2("Command not found : ", cmd->cmd[0]), -1);
	if (execve(cmd->path, cmd->cmd, cmd->path_env) == -1)
		return (-1);
	return (0);
}

int	dup_in(t_cmd cmd, t_info global_info, int runner)
{
	if (runner == 0)
	{
		if (dup2(global_info.infilefd, STDIN_FILENO) == -1)
			return (-1);
		if (global_info.infilefd != -1)
			close(global_info.infilefd);
	}
	else
	{
		if (dup2(cmd.fdin, STDIN_FILENO) == -1)
			return (-1);
		if (global_info.infilefd != -1)
			close(global_info.infilefd);
		close(cmd.fdin);
	}
	return (0);
}

int	dup_out(t_info global_info, int runner, int *fd)
{
	if (runner == global_info.nb_cmds - 1)
	{
		if (dup2(global_info.outfilefd, STDOUT_FILENO) == -1)
			return (-1);
		if (global_info.outfilefd != -1)
			close(global_info.outfilefd);
	}
	else
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return (-1);
		close(fd[1]);
		if (global_info.outfilefd != -1)
			close(global_info.outfilefd);
	}
	return (0);
}
