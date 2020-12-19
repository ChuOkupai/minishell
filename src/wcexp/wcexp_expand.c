/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:59:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/16 15:17:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "wcexp.h"

static void		check_dot(t_wcexp *w)
{
	t_token	*t;
	char	*buf;

	if (!w->l)
		return ;
	t = w->l->content;
	if (*t->value == '/' || !ft_strncmp(t->value, "./", 2))
		return ;
	w->dot = true;
	if (!token_is_dynamic(t))
	{
		t = token_new(TOKEN_WORD, ft_strdup("./"));
		ft_list_push(&w->l, ft_list_new(t));
		return ;
	}
	buf = ft_strjoin("./", t->value);
	ft_free(t->value);
	t->value = buf;
}

static t_list	*discard_dot(t_list *l)
{
	t_list	*e;
	char	*s;

	e = l;
	while (e)
	{
		s = e->content;
		ft_memmove(s, s + 2, ft_strlen(s) - 1);
		e = e->next;
	}
	return (l);
}

t_list			*wcexp_expand(t_wcexp *w)
{
	t_list *ent;

	ent = NULL;
	w->l = ft_list_rev(w->l);
	check_dot(w);
	while (w->l)
		ent = wcexp_expand_expr(w, ent);
	if (w->dot)
		ent = discard_dot(ent);
	ft_list_sort(&ent, (t_gcompare) & ft_strcmp);
	return (ent);
}
