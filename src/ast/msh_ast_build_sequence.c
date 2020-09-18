/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_build_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:03:23 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 14:17:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "parser.h"

static t_redirection	*create_redirection(t_list **l)
{
	t_token			*op;
	t_token			*path;
	t_redirection	*r;

	op = ft_list_pop(l, NULL);
	path = ft_list_pop(l, NULL);
	r = msh_redirect_new(msh_redirect_type(op->value), path->value);
	free(op);
	free(path);
	return (r);
}

static t_process		*create_process(t_list **argv, t_list **redir)
{
	t_process *p;

	*argv = ft_list_rev(*argv);
	p = msh_process_new(ft_list_to_array(*argv), ft_list_rev(*redir));
	ft_list_clear(argv, NULL);
	*redir = NULL;
	return (p);
}

t_list					*msh_ast_build_sequence(t_list **l)
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
			ft_list_push(&argv, msh_token(ft_list_pop(l, NULL))->value);
			free(t);
		}
		else if (t->type == TOKEN_REDIRECT)
			ft_list_push(&redir, create_redirection(l));
		else if (t->type == TOKEN_PIPE)
			ft_list_push(&seq, create_process(&argv, &redir));
		else
			break ;
	return (ft_list_rev(seq));
}
