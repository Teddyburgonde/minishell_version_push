/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:47:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/07 11:26:25 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_lstclear_redirections(t_redirection_to_expand **lst)
{
	t_redirection_to_expand	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->arg)
			free(tmp->arg);
		free(tmp);
	}
}

void	ft_lstclear_arguments(t_argument_to_expand **lst)
{
	t_argument_to_expand	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
}

void	ft_lstclear_commands(t_command_to_expand **lst)
{
	t_command_to_expand	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->arguments)
			ft_lstclear_arguments(&tmp->arguments);
		if (tmp->redirections)
			ft_lstclear_redirections(&tmp->redirections);
		free(tmp);
	}
}

void	ft_lstclear_char_list(t_char_list **lst)
{
	t_char_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	ft_lstclear_argument(t_argument **lst)
{
	t_argument	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->chars)
			ft_lstclear_char_list(&tmp->chars);
		free(tmp);
	}
}
