/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/15 15:24:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ast.h"
#include "parser.h"
#include "shell.h"

static void	init(t_shell *s)
{
	shell_hook(s);
	shell_update_prompts(s);
	s->keep = true;
}

static void	launch(t_shell *s)
{
	t_btree *ast;

	s->discard = false;
	if ((s->options & OPT_DUMP_AST) && s->asts)
		ft_list_print(s->asts, (t_gprint) & astnode_print);
	while (s->asts)
	{
		ast = s->asts->content;
		if (!s->discard && s->keep)
			ast_exec(ast, s);
		astnode_clear(ft_list_pop(&s->asts));
	}
}

static int	quit_with_status(t_shell *s)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return (s->env.status.value);
}

int			shell_run(t_shell *s)
{
	t_list	*l;
	bool	update;

	init(s);
	while (s->keep)
	{
		l = shell_read_command(s);
		if ((s->options & OPT_DUMP_TOKENS) && l)
			ft_list_print(l, (t_gprint) & token_print);
		s->asts = ast_build(l);
		update = s->asts != NULL;
		launch(s);
		if (update)
			shell_update_prompts(s);
	}
	return (quit_with_status(s));
}
