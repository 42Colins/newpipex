#include "../inc/pipex.h"

int		cmd_exec(t_cmd *cmd, int runner, t_info global_info, int *fd);
int		dup_in(t_cmd cmd, t_info global_info, int runner);
int		dup_out(t_info global_info, int runner, int *fd);
void	free_tab(char **str);

void    do_exec(t_cmd *cmd, t_info *global_info)
{
	int runner;
	int fd[2];

	runner = 0;
	global_info->infilefd = open(global_info->infile, O_RDONLY);
	cmd[0].fdin = global_info->infilefd;
	global_info->outfilefd = open(global_info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (global_info->outfilefd == -1)
		exit(1);
	while (runner < global_info->nb_cmds)
	{
		if (pipe(fd) == -1)
			exit(1);
		cmd[runner].pid = fork();
		if (cmd[runner].pid == -1)
			return ;
		if (cmd[runner].pid == 0)
		{
//			free_a_bit(global_info);
			if (cmd_exec(&cmd[runner], runner, *global_info, fd) != 0)
				free_cmd(cmd, global_info);
		}
		else
		{
			if (runner + 1 < global_info->nb_cmds)
				cmd[runner + 1].fdin = fd[0];
			close(fd[1]);
		}
		runner++;
	}
}

int cmd_exec(t_cmd *cmd, int runner, t_info global_info, int *fd)
{
	if (dup_in(*cmd, global_info, runner) != 0)
		return(-1);
	if (dup_out(global_info, runner, fd) != 0)
		return(-1);
	if (execve(cmd->path, cmd->cmd, cmd->path_env) == -1)
		return(-1);
	return(0);
}

int    dup_in(t_cmd cmd, t_info global_info, int runner)
{
	if (runner == 0)
	{
		if (dup2(global_info.infilefd, STDIN_FILENO) == -1)
			return(-1);
		close(global_info.infilefd);
	}
	else
	{
		if (dup2(cmd.fdin, STDIN_FILENO) == -1)
			return(-1);
		close(cmd.fdin);
	}
	return(0);
}

int    dup_out(t_info global_info, int runner, int *fd)
{
	if (runner == global_info.nb_cmds - 1)
	{
		if (dup2(global_info.outfilefd, STDOUT_FILENO) == -1)
			return(-1);
		close(global_info.outfilefd);
	}
	else
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return(-1);
		close(fd[1]);
	}
	return(0);
}

//if (index == 0)
//global_info->infilefd = dup_in(global_info, fd);
//else if (index == global_info->nb_cmds)
//global_info->outfile = dup_out(global_info, fd);
//else