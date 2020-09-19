/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_build_seq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:03:23 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/19 13:54:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "parser.h"

static char	*pop_token(t_token *t)
{
	char *value;

	value = t->value;
	free(t);
	return (value);
}

static void	create_redirection(t_list **l, t_list **r)
{
	t_list	*tmp;
	t_token	*op;

	tmp = ft_list_popl(l);
	op = msh_token(tmp);
	tmp->content = msh_redirect_new(msh_redirect_type(op->value),
	pop_token(ft_list_pop(l, NULL)));
	ft_list_pushl(r, tmp);
}

static void	create_process(t_list **seq, t_list *argv, t_list *redir)
{
	argv = ft_list_rev(argv);
	redir = ft_list_rev(redir);
	ft_list_push(seq, msh_process_new((char**)ft_list_to_array(argv), redir));
	ft_list_clear(&argv, NULL);
}

static void	create_pipeline(t_list **l, t_list **seq, t_list **argv,
			t_list **redir)
{
	ft_list_pop(l, NULL);
	create_process(seq, *argv, *redir);
	*argv = NULL;
	*redir = NULL;
}

t_list		*msh_ast_seq(t_list **l)
{
	t_list		*seq;
	t_list		*argv;
	t_list		*redir;
	t_token		*t;

	seq = NULL;
	argv = NULL;
	redir = NULL;
	while ((t = msh_token(*l)))
		if (t->type == TOKEN_WORD)
		{
			ft_list_pushl(&argv, ft_list_popl(l));
			argv->content = pop_token(t);
		}
		else if (t->type == TOKEN_REDIRECT)
			create_redirection(l, &redir);
		else if (t->type == TOKEN_PIPE)
			create_pipeline(l, &seq, &argv, &redir);
		else
			break ;
	if (argv || redir)
		create_process(&seq, argv, redir);
	return (ft_list_rev(seq));
}
