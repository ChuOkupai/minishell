/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:42:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 15:24:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "job.h"
#include "utils.h"

static t_shell	*g_shell;

static void	catch_ctrl_c(int signal)
{
	g_shell->discard = true;
	ft_putchar('\n');
	if (g_shell->job)
		job_kill(g_shell->job, signal);
	else
	{
		if (g_shell->ps1)
			ft_putstr_fd(g_shell->ps1, STDERR_FILENO);
		env_setstatus(&g_shell->env, 130);
	}
}

static void	catch_ctrl_backslash(int signal)
{
	if (g_shell->job)
	{
		job_kill(g_shell->job, signal);
		ft_dprintf(STDERR_FILENO, "%s (core dumped)\n", msh_strsig(signal));
		env_setstatus(&g_shell->env, 131);
	}
	else
	{
		ft_putstr("\b\b  \b\b\n");
		if (g_shell->showps2 && g_shell->ps2)
			ft_putstr_fd(g_shell->ps2, STDERR_FILENO);
		else if (g_shell->ps1)
			ft_putstr_fd(g_shell->ps1, STDERR_FILENO);
	}
}

void		shell_hook(t_shell *s)
{
	g_shell = s;
	signal(SIGINT, &catch_ctrl_c);
	signal(SIGQUIT, &catch_ctrl_backslash);
}

bool		shell_interrupted(void)
{
	return (g_shell->discard);
}
