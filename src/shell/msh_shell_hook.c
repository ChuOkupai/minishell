/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:42:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/04 17:43:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "shell.h"

static t_shell	*g_shell;

static void	catch_ctrl_c(int signal)
{
	ft_putchar('\n');
	if (g_shell->pid)
		kill(g_shell->pid, signal);
	else
	{
		if (g_shell->ps1)
			ft_putstr(g_shell->ps1);
		g_shell->discard = true;
		msh_env_setstatus(&g_shell->env, 130);
	}
}

static void	catch_ctrl_backslash(int signal)
{
	if (g_shell->pid)
	{
		kill(g_shell->pid, signal);
		msh_env_setstatus(&g_shell->env, 131);
	}
}

void		msh_shell_hook(t_shell *s)
{
	g_shell = s;
	signal(SIGINT, &catch_ctrl_c);
	signal(SIGQUIT, &catch_ctrl_backslash);
}
