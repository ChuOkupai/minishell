/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:46:57 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/09 00:52:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "process.h"
#include "utils.h"

static void	clear_on_exit(t_shell *s, int ret)
{
	shell_clear(s);
	exit(ret);
}

void		process_exec(t_process *p, t_shell *s)
{
	t_builtin	func;
	char		*bin;

	if (process_redirect(p) < 0)
		clear_on_exit(s, 1);
	else if (!*p->argv)
		clear_on_exit(s, 0);
	func = get_builtin(*p->argv);
	if (func)
		clear_on_exit(s, func(p->argv, s));
	bin = env_abspath(&s->env, *p->argv);
	if (!bin)
		clear_on_exit(s, msh_perrorr(*p->argv, "command not found", 127));
	execve(bin, p->argv, s->env.array);
	if (msh_isdir(bin))
		errno = EISDIR;
	clear_on_exit(s, msh_perrorr(bin, msh_strerrno(), 126));
}
