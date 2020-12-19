/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:48:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 11:35:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "wcexp.h"

static t_list	*split(t_list **l, t_token *t)
{
	char	*s;
	t_token	*d;

	s = ft_strchr(t->value, '/');
	if (!*(++s))
		return (ft_list_popl(l));
	d = token_new(TOKEN_WORD, t->value);
	t->value = ft_strdup(s);
	*s = '\0';
	return (ft_list_new(d));
}

static char		*extract_prefix(t_list **l)
{
	t_token	*t;
	char	*d;
	char	*buf;

	t = (*l)->content;
	if (!(*l)->next || t->type == TOKEN_WILDCARD)
		return (NULL);
	d = ft_strrchr(t->value, '/');
	if (!d)
		return (NULL);
	if (!d[1])
		return (token_pop(ft_list_pop(l)));
	buf = t->value;
	t->value = ft_strdup(d + 1);
	d[1] = '\0';
	return (buf);
}

static bool		extract_keep_dir(t_list **l)
{
	t_token	*t;
	size_t	n;

	t = (*l)->content;
	if (t->type == TOKEN_WILDCARD || !(n = ft_strlen(t->value))
	|| t->value[n - 1] != '/')
		return (false);
	if (n == 1)
		token_clear(ft_list_pop(l));
	else
		t->value[n - 1] = '\0';
	return (true);
}

void			wcexp_next(t_wcexp *w, t_expr *e)
{
	bool	wc;
	t_token	*t;

	e->pattern = NULL;
	wc = false;
	while (w->l)
		if (ft_strchr((t = w->l->content)->value, '/') && wc)
		{
			ft_list_push(&e->pattern, split(&w->l, t));
			break ;
		}
		else
		{
			ft_list_push(&e->pattern, ft_list_popl(&w->l));
			wc |= t->type == TOKEN_WILDCARD;
		}
	e->keep_dir = extract_keep_dir(&e->pattern);
	e->pattern = ft_list_rev(e->pattern);
	e->prefix = extract_prefix(&e->pattern);
	t = e->pattern->content;
	e->keep_hidden = t->type == TOKEN_WORD && *t->value == '.';
}
