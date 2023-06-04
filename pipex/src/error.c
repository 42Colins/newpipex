#include "../inc/pipex.h"

void	free_tab(char **str);

void free_cmd(t_cmd *cmd, t_info *global_info)
{
	int runner;

	runner = 0;
	while (runner < global_info->nb_cmds)
	{
		free(cmd[runner].path);
		free_tab(cmd[runner].cmd);
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

void open_in_failed(t_cmd *cmd, t_info *global_info)
{
    int runner;

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


void free_a_bit(t_info *global_info)
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
	while(str[runner])
	{
		free(str[runner]);
		runner++;
	}
	free(str);
}

void    ft_error(char *s1)
{
    s1 = ft_strjoin(s1, "\n");
    ft_putstr_fd(s1, 2);
    free(s1);
}

void    ft_error2(char *s1, char *s2)
{
    s1 = ft_strjoin(s1, s2);
    s1 = ft_strjoin2(s1, "\n");
    ft_putstr_fd(s1, 2);
    free(s1);
}