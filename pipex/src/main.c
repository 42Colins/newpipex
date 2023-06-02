//
// Created by cprojean on 6/1/23.
//
#include "../inc/pipex.h"

void    print_all(t_cmd *cmd, t_info *global_info);


int	main(int argc, char **argv, char **env)
{
	int	runner;
	t_cmd	*cmd;
	t_info	global_info;

	if (argc < 5)
		ft_putstr_fd("Error, Wrong number of arguments\n", 2);
	else
	{
		cmd = malloc(sizeof(t_cmd) * (argc - 3));
		runner = 0;
		global_info = global_parse(&global_info, argv, argc);
		while(runner < argc - 3)
		{
			ft_bzero(&cmd[runner], sizeof(t_cmd));
			cmd[runner] = parse_cmds(&cmd[runner], runner, argv, env);
			runner++;
		}
		print_all(&cmd[0], &global_info);
		print_all(&cmd[1], &global_info);
		print_all(&cmd[2], &global_info);
		do_exec(&cmd, &global_info);
		wait_all(&cmd, &global_info);
	}
}

void    print_all(t_cmd *cmd, t_info *global_info)
{
	ft_printf("%s\n", cmd->cmd[0]);
	ft_printf("%s\n", cmd->path);
	ft_printf("%s\n", global_info->infile);
	ft_printf("%s\n", global_info->outfile);
}
//			if (cmd[runner]->error != 0)
//				parsing_error(cmd[runner]);