/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:27:44 by cprojean          #+#    #+#             */
/*   Updated: 2023/06/04 18:27:43 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(t_cmd *cmd);
void	free_split(char **str);

void	parse_cmds(t_cmd *cmd, int runner, char **argv, char **env)
{
	cmd->error = 0;
	cmd->path_env = find_env_path(env);
	cmd->cmd = ft_split(argv[runner + 2], ' ');
	if (!cmd->cmd)
		cmd->error = -1;
	cmd->path = find_path(cmd);
	if (cmd->path == NULL)
		cmd->error = -2;
}

void	global_parse(t_info *global_info, char **argv, int argc)
{
	global_info->nb_cmds = argc - 3;
	global_info->infile = argv[1];
	global_info->outfile = argv[argc - 1];
	global_info->infilefd = -1;
	global_info->outfilefd = -1;
}

char	*find_path(t_cmd *cmd)
{
	char	*cmd_path;
	char	*tmp;
	int		runner;

	runner = 0;
	if (is_slash(cmd->cmd[0]) && access(cmd->cmd[0], F_OK | X_OK) == 0)
		return (cmd->cmd[0]);
	if (is_slash(cmd->cmd[0]))
		return (NULL);
	if (cmd->cmd != NULL)
	{
		while (cmd->path_env[runner])
		{
			tmp = ft_strjoin(cmd->path_env[runner], "/");
			cmd_path = ft_strjoin(tmp, cmd->cmd[0]);
			if (tmp)
				free(tmp);
			if (access(cmd_path, F_OK | X_OK) == -1)
				free(cmd_path);
			else
				return (cmd_path);
			runner++;
		}
	}
	return (NULL);
}

char	**find_env_path(char **env)
{
	int		runner;
	char	*tmp;

	runner = 0;
	if (!env)
		return (NULL);
	while (env[runner])
	{
		if (ft_strncmp("PATH=", env[runner], 5) == 0)
			tmp = env[runner];
		runner++;
	}
	return (ft_split(&tmp[5], ':'));
}

void	parsing_error(t_cmd *cmd)
{
	if (cmd->error == -1)
		ft_putstr_fd("Split broke\n", 2);
	if (cmd->error == -2)
	{
		ft_putstr_fd("Error : Command not found\n", 2);
		free_split(cmd->cmd);
		exit(-1);
	}
}
