/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:07:29 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/19 15:23:52 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtin.h"
#include "job.h"
#include "utils.h"

static void	dump_exec(const t_list *j)
{
	ft_putstr("+ ");
	job_print(j);
	ft_putchar('\n');
}

static bool	try_exec_builtin(t_process *p, t_shell *s)
{
	t_builtin	f;
	int			input;
	int			output;

	f = get_builtin(*p->argv);
	if (!f)
		return (false);
	input = dup(STDIN_FILENO);
	output = dup(STDOUT_FILENO);
	if (input < 0 || output < 0)
		msh_abort("dup");
	process_terminate(p, (process_redirect(p) < 0 ? 1 : f(p->argv, s)));
	job_close_fd(input, output, true);
	return (true);
}

int			job_exec(t_list *j, t_shell *s)
{
	s->job = j;
	job_expand(j, &s->env);
	s->job = NULL;
	if (shell_interrupted())
		return (s->env.status.value);
	if (s->options & OPT_DUMP_EXEC)
		dump_exec(j);
	s->showps2 = true;
	job_create_heredoc(j, s);
	s->showps2 = false;
	if (shell_interrupted())
		return (s->env.status.value);
	if (j->next || !try_exec_builtin(j->content, s))
	{
		job_fork(j, s, STDIN_FILENO);
		s->job = j;
		job_wait(j);
		s->job = NULL;
	}
	return (process(ft_list_last(j)->content)->status);
}
