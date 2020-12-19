/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_seq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:03:23 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:41:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "parser.h"
#include "process.h"

static t_list		*create_arg(t_list **l)
{
	t_list *dst;

	dst = ft_list_popl(l);
	dst->content = token_pop(dst->content);
	return (dst);
}

static t_list		*create_redirection(t_list **l)
{
	t_token		*redir;
	t_redir_op	op;
	t_list		*dst;

	redir = ft_list_pop(l);
	op = redir_op(redir->value);
	dst = ft_list_popl(l);
	dst->content = redir_new(op, token_pop(dst->content));
	return (dst);
}

static t_process	*create_process(t_list **l)
{
	t_list	*argv;
	t_list	*redir;
	t_token	*t;

	argv = NULL;
	redir = NULL;
	while (*l && (t = (*l)->content))
		if (t->type == TOKEN_WORD)
			ft_list_push(&argv, create_arg(l));
		else if (t->type == TOKEN_REDIRECT)
			ft_list_push(&redir, create_redirection(l));
		else
			break ;
	if (!argv && !redir)
		return (NULL);
	return (process_new(ft_list_rev(argv), ft_list_rev(redir)));
}

t_btree				*ast_build_seq(t_list **l)
{
	t_list		*seq;
	t_process	*p;

	seq = NULL;
	while ((p = create_process(l)))
	{
		ft_list_push(&seq, ft_list_new(p));
		if (*l && token((*l)->content)->type == TOKEN_PIPE)
			ft_list_pop(l);
	}
	return (astnode_new(AST_JOB, ft_list_rev(seq)));
}
