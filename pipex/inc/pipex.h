/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:23:08 by cprojean          #+#    #+#             */
/*   Updated: 2023/06/05 13:10:59 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_cmd{
	char	**cmd;
	char	*path;
	char	**path_env;
	int		pid;
	int		fdin;
	int		error;
}	t_cmd;

typedef struct s_information
{
	char	*infile;
	int		infilefd;
	char	*outfile;
	int		outfilefd;
	int		nb_cmds;
}	t_info;

void	parse_cmds(t_cmd *cmd, int runner, char **argv, char **env);
void	global_parse(t_info *global_info, char **argv, int argc);
void	do_exec(t_cmd *cmd, t_info *global_info);
char	**find_env_path(char **env);
void	wait_all(t_cmd *cmd, t_info *global_info);
void	free_cmd(t_cmd *cmd, t_info *global_info);
void	free_a_bit(t_info *global_info);
int		close_fds(t_cmd *cmd, t_info *global_info, int *fd);
void	open_in_failed(t_cmd *cmd, t_info *global_info);
void	ft_error(char *s1);
void	ft_error2(char *s1, char *s2);
void	free_split(char **str);
int		is_slash(char *str);
void	free_tab(char **str);
void	free_on_error(t_info *global_info, t_cmd *cmd, int index);
void	double_close(int *fd);



#endif
