/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:47:35 by rgobet            #+#    #+#             */
/*   Updated: 2024/07/13 22:34:48 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	manage_export(char **command_line,
	t_redirection *redirect, t_vars **vars, t_env **env)
{
	char	**envp;
	t_env	*tmp;

	tmp = *env;
	envp = NULL;
	if (ft_strcmp(command_line[0], "export") == 0
		&& ft_strlen(command_line[0]) > 0)
	{
		if (command_line[1])
			(*vars)->exit_code = export(env, command_line, *vars);
		else
		{
			envp = env_to_char_export(tmp);
			print_env(envp, *vars, redirect);
			if (envp)
				ft_free(envp);
		}
		return (0);
	}
	return (1);
}

int	manage_env(char **command_line, t_vars **vars, t_redirection *redirect)
{
	if ((ft_strcmp(command_line[0], "printenv") == 0
			|| ft_strcmp(command_line[0], "env") == 0)
		&& ft_strlen(command_line[0]) > 0)
	{
		exec_env(command_line, *vars, redirect);
		return (0);
	}
	return (1);
}

t_bool	is_builtins_exec(t_vars *vars)
{
	if (vars && vars->cmd_index && vars->cmd[vars->cmd_index - 1][0]
		&& (ft_strcmp(vars->cmd[vars->cmd_index - 1][0], "unset") == 0
		|| ft_strcmp(vars->cmd[vars->cmd_index - 1][0], "export") == 0
		|| ft_strcmp(vars->cmd[vars->cmd_index - 1][0], "cd") == 0
		|| ft_strcmp(vars->cmd[vars->cmd_index - 1][0], "pwd") == 0
		|| ft_strcmp(vars->cmd[vars->cmd_index - 1][0], "echo") == 0
		|| ft_strcmp(vars->cmd[vars->cmd_index - 1][0], "exit") == 0
		|| ft_strcmp(vars->cmd[vars->cmd_index - 1][0], "env") == 0))
		return (TRUE);
	return (FALSE);
}

t_bool	is_builtins_parsing(char **str)
{
	if (str == NULL || str[0] == NULL)
		return (FALSE);
	if (ft_strcmp(str[0], "unset") == 0
		|| ft_strcmp(str[0], "export") == 0
		|| ft_strcmp(str[0], "cd") == 0
		|| ft_strcmp(str[0], "pwd") == 0
		|| ft_strcmp(str[0], "echo") == 0
		|| ft_strcmp(str[0], "exit") == 0
		|| ft_strcmp(str[0], "env") == 0)
		return (TRUE);
	return (FALSE);
}
