/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strsig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:48:54 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 14:57:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef NSIG
# define NSIG	32
#endif

static void	set_entry(const char **tab, size_t i, const char *message)
{
	if (i < NSIG)
		tab[i] = message;
}

static bool	init_jump_table(const char **tab)
{
	set_entry(tab, SIGQUIT, "Quit");
	set_entry(tab, SIGILL, "Illegal instruction");
	set_entry(tab, SIGABRT, "ABORT instruction");
	set_entry(tab, SIGBUS, "Bus error");
	set_entry(tab, SIGFPE, "Floating point exception");
	set_entry(tab, SIGKILL, "Killed");
	set_entry(tab, SIGSEGV, "Segmentation fault");
	set_entry(tab, SIGPIPE, "Broken pipe");
	set_entry(tab, SIGSYS, "Bad system call");
	return (true);
}

const char	*msh_strsig(int signum)
{
	static const char	*siglist[NSIG] = { 0 };
	static bool			init = false;

	if (!init)
		init = init_jump_table(siglist);
	if (signum < 0 || signum >= NSIG)
		return (NULL);
	return (siglist[signum]);
}
