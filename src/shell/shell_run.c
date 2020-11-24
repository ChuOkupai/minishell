/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 15:25:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ast.h"
#include "parser.h"
#include "shell.h"

static void	init(t_shell *s)
{
	shell_hook(s);
	s->line_no = 1;
	s->keep = true;
}

static void	run_command(t_shell *s, t_btree *ast)
{
	ast_exec(ast, s);
	ft_btree_clear(&ast, (t_gfunction) & ast_clear);
}

static int	quit_with_status(t_shell *s)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return (s->env.status);
}

int			shell_run(t_shell *s)
{
	t_list *l;

	init(s);
	while (s->keep)
	{
		l = shell_read_command(s);
		if (s->options.dump_tokens && l)
			ft_list_print(l, (t_gprint) & token_print);
		if ((l = ast_build(l)))
			++s->line_no;
		if (s->options.dump_ast && l)
			ft_list_print(l, (t_gprint) & astnode_print);
		while (l)
			run_command(s, ft_list_pop(&l));
	}
	return (quit_with_status(s));
}
