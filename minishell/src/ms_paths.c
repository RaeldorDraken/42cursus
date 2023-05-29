/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:53:24 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/29 12:16:12 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

char	*msh_getpath_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i ++;
	i --;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0 && i != 0)
		i --;
	if (i == 0)
		return (NULL);
	return (envp[i]);
}

void	msh_getpath(t_vars *vars, char **envp)
{
	char	*path_line;
	int		i;

	path_line = msh_getpath_line(envp);
	if (path_line == NULL)
		path_line = "PATH=./";
	i = ft_strlen(path_line);
	path_line = ft_substr(path_line, 5, i);
	i = -1;
	vars->paths = ft_split(path_line, ':');
}

char	*msh_getpath_cmd(t_vars *vars, char *cmd)
{
	int		i;
	char	*path_cmd;
	char	*tmp;

	i = 0;
	path_cmd = NULL;
	while (vars->paths[i] != NULL)
	{
		tmp = ft_strjoin(vars->paths[i], "/");
		path_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path_cmd, F_OK) == 0)
			break ;
		free(path_cmd);
		path_cmd = NULL;
		i++;
	}
	return (path_cmd);
}

int	msh_cmd_execute(t_vars *vars, char **envp)
{
	char	*cmd;
	int		i;

	cmd = NULL;
	if (vars->cmd_buffer != NULL)
	{
		i = -1;
		while (vars->cmd_buffer[++i] && vars->cmd_buffer[i] != NULL)
		{
			free(vars->cmd_buffer[i]);
		}
		free(vars->cmd_buffer);
		vars->cmd_buffer = NULL;
	}
	vars->cmd_buffer = msh_get_cmds(vars, 0); //cambiar 0 por una forma de comprobar si va despues de un token
	cmd = msh_getpath_cmd(vars, vars->cmd_buffer[0]);
	if (cmd && vars->cmd_buffer[0])
	{
		execve(cmd, vars->cmd_buffer, envp); //here it exits the program i need to put a fork before this
			write(1, "Printing stuff to check where it breaks\n", 41);
		free(cmd);
		return (1);
	}
	else
	{
		free(cmd);
	//	cmd_error(vars->cmd_buffer);
		return (0);
	}
}

char	**msh_get_cmds(t_vars *vars, int i)
{
	int		j;
	int		k;
	char	**cmds;

	k = 0;
	cmds = ft_calloc(sizeof(char *), ft_arrsize(vars->inpcomm) + 1);
	if (cmds == NULL)
		return (NULL);
	while (vars->inpcomm[i] != NULL)
	{
		j = -1;
		while (vars->tokens[++j] != NULL)
		{
			if (vars->inpcomm[i] == vars->tokens[j])
			{
				cmds[k] = NULL;
				return (cmds);
			}
		}
		cmds[k] = vars->inpcomm[i];
		k++;
		i++;
	}
	cmds[k] = NULL;
	return (cmds);
}

//write(1, "Printing stuff to check where it breaks/n", 41);