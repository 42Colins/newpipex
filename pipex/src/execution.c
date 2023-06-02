#include "../inc/pipex.h"

int cmd_exec(t_cmd *cmd);

void    do_exec(t_cmd **cmd, t_info *global_info)
{
	int runner;

	runner = 0;
	if (global_info->infilefd == -1)
		return ;
	global_info->infilefd = open(global_info->infile, O_RDONLY);
	cmd[0]->fdin = global_info->infilefd;
	global_info->outfilefd = open(global_info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (global_info->outfilefd == -1)
		return ;
//	ft_printf("%s", cmd[runner]->cmd[0]);
	while (runner < global_info->nb_cmds)
	{
		ft_printf("%d\n", runner);
		cmd[runner]->pid = fork();
		if (cmd[runner]->pid == -1)
			return ;
		if (cmd[runner]->pid == 0)
		{
			if (runner == global_info->nb_cmds - 1)
			{
				cmd[runner + 1]->pipe[1] = global_info->outfilefd;
				cmd_exec(cmd[runner]);
			}
			else
			{
				cmd[runner]->fdin = cmd_exec(cmd[runner]);
			}
		}
		runner++;
	}
}

int cmd_exec(t_cmd *cmd)
{
	if (dup2(cmd->fdin, STDIN_FILENO) == -1)
		exit(1);
	close(cmd->fdin);
	if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
		exit(1);
	close(cmd->pipe[1]);
	if (execve(cmd->path, cmd->cmd, cmd->path_env) == -1)
		exit(1);
	return(0);
}

//if (index == 0)
//global_info->infilefd = dup_in(global_info, fd);
//else if (index == global_info->nb_cmds)
//global_info->outfile = dup_out(global_info, fd);
//else