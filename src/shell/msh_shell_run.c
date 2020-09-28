/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 17:49:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ast.h"
#include "parser.h"
#include "shell.h"
#include "utils.h"

static void	execute_cmds(t_list *l, t_shell *shell)
{
	t_btree	*b;

	while (l)
	{
		msh_ast_exec((b = msh_astnode(l)), shell);
		ft_btree_clear(&b, (t_gfunction) & msh_ast_clear);
		ft_list_pop(&l, NULL);
	}
}

static void	interpret(t_shell *s)
{
	t_list	*l;
	int		r;

	if (!(l = msh_tokenize(s->line.buf)))
		return ;
	if (!(r = msh_is_valid(l)) || r < 0)
	{
		if (r < 0)
			msh_perror("warning: Unsupported multiline commands");
		ft_list_clear(&l, (t_gfunction) & msh_token_clear);
		return ;
	}
	msh_parse_words(l, &s->env);
	if (s->options.dump_tokens)
		ft_list_print(l, (t_gprint) & msh_token_print);
	l = msh_ast_build(l);
	if (s->options.dump_ast)
		ft_list_print(l, (t_gprint) & msh_astnode_print);
	execute_cmds(l, s);
}

static void	history_add_command(t_history *history, char *command)
{
	t_list *l;

	if (history->size == history->histsize)
	{
		l = ft_list_at(history->commands, history->size--);
		ft_list_clear(&l, &free);
	}
	if (history->histsize)
		ft_list_push(&history->commands, ft_strdup(command));
}

int			msh_shell_run(t_shell *s)
{
	s->keep = true;
	while (s->keep && !msh_shell_readline(s))
	{
		if (!*s->line.buf)
			continue ;
		history_add_command(&s->history, s->line.buf);
		interpret(s);
	}
	return (0);
}
