/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/04 16:47:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ast.h"
#include "parser.h"
#include "shell.h"

static void	init(t_shell *s)
{
	msh_shell_hook(s);
	s->line_no = 1;
	s->keep = true;
}

static void	run_command(t_shell *s, t_btree *ast)
{
	msh_ast_exec(ast, s);
	ft_btree_clear(&ast, (t_gfunction) & msh_ast_clear);
}

static int	quit_with_status(t_shell *s)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return (s->env.status);
}

int			msh_shell_run(t_shell *s)
{
	t_list *l;

	init(s);
	while (s->keep)
	{
		l = msh_shell_read_command(s);
		if (s->options.dump_tokens && l)
			ft_list_print(l, (t_gprint) & msh_token_print);
		if ((l = msh_ast_build(l)))
			++s->line_no;
		if (s->options.dump_ast && l)
			ft_list_print(l, (t_gprint) & msh_astnode_print);
		while (l)
			run_command(s, ft_list_pop(&l));
	}
	return (quit_with_status(s));
}
