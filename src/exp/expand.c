/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:26:23 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 16:40:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

void	expand(t_exp *w, const char *s)
{
	t_string dst;

	wcexp_init(&w->wc);
	if (!s)
		return ;
	ft_bzero(&dst, sizeof(dst));
	exp_word(w, &dst, s);
	if (!dst.buf && ft_strchr("'\"", *s))
		dst.buf = ft_strdup("");
	w->dst = dst.buf;
	w->wc_found = !!w->wc.l;
	if (w->flags & EXP_WILDCARD && w->wc.l)
	{
		wcexp_flush(&w->wc, &dst);
		w->args = wcexp_expand(&w->wc);
	}
}
