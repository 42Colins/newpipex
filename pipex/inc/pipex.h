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
	int     error;
	int     pid;
	int     fdin;
	int     pipe[2];
}	t_cmd;

typedef struct s_information
{
	char	*infile;
	int     infilefd;
	char	*outfile;
	int     outfilefd;
	int		nb_cmds;
}	t_info;

t_cmd   parse_cmds(t_cmd *cmd, int runner, char **argv, char **env);
t_info  global_parse(t_info *global_info, char **argv, int argc);
void    do_exec(t_cmd **cmd, t_info *global_info);
char	**find_env_path(char **env);
void    wait_all(t_cmd **cmd, t_info *global_info);


#endif
