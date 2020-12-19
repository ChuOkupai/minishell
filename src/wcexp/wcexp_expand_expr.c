/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp_expand_expr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:37:47 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/15 13:46:53 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "token.h"
#include "wcexp.h"
#include "utils.h"

static t_list	*append_prefix(t_list *l, char *prefix)
{
	t_list	*e;
	char	*b;

	if (!prefix)
		return (l);
	if (!l)
		return (ft_list_push(&l, ft_list_new(prefix)));
	e = l;
	while (e)
	{
		b = ft_strjoin(e->content, prefix);
		ft_free(e->content);
		e->content = b;
		e = e->next;
	}
	ft_free(prefix);
	return (l);
}

static void		discard_wrong_match(t_list *l, const char *prefix, t_expr *e)
{
	char *b;

	if (!l || shell_interrupted())
		return ;
	if (wcexp_match(l->content, e->pattern))
	{
		b = ft_strjoin3(prefix, l->content, (e->keep_dir ? "/" : NULL));
		ft_free(l->content);
		l->content = e->keep_dir && !msh_isdir(b) ? ft_free(b) : b;
	}
	else
		l->content = ft_free(l->content);
	discard_wrong_match(l->next, prefix, e);
}

static t_list	*expand_dir(t_list *l, t_expr *e)
{
	t_list	*ent;
	t_list	*f;

	ent = NULL;
	while (l)
	{
		if (shell_interrupted())
		{
			ft_list_clear(&l, (t_gfunction) & ft_free);
			break ;
		}
		f = wcexp_readdir(l->content, e->keep_hidden);
		discard_wrong_match(f, l->content, e);
		ft_list_remove_if(&f, NULL, &ft_compare_pointer, NULL);
		ent = ft_list_merge(ent, f);
		ft_free(ft_list_pop(&l));
	}
	return (ent);
}

t_list			*wcexp_expand_expr(t_wcexp *w, t_list *ent)
{
	t_expr e;

	wcexp_next(w, &e);
	ent = append_prefix(ent, e.prefix);
	ent = expand_dir(ent, &e);
	ft_list_clear(&e.pattern, (t_gfunction) & token_clear);
	if (shell_interrupted())
		ft_list_clear(&ent, (t_gfunction) & ft_free);
	if (!ent)
		wcexp_clear(w);
	return (ent);
}
