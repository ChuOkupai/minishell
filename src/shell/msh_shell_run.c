/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 17:21:03 by asoursou         ###   ########.fr       */
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

static void	interpret(t_shell *s, const char *str)
{
	t_list	*l;
	int		r;

	if (!(l = msh_tokenize(str)))
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

int			msh_shell_run(t_shell *s)
{
	char *str;

	s->keep = true;
	while (s->keep && (str = msh_readline(&s->readline, &s->history, s->ps1)))
	{
		if (*ft_strwhile(str, &ft_isspace))
			msh_history_add(&s->history, str);
		interpret(s, str);
		ft_memdel(str);
	}
	return (0);
}
