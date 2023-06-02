#include "../inc/pipex.h"

void    wait_all(t_cmd **cmd, t_info *global_info)
{
	int runner;

	runner = global_info->nb_cmds;
	while (runner > 0)
	{
		waitpid(cmd[runner]->pid, NULL, 0);
		runner--;
	}
}