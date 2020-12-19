/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:47 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 13:07:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

static void	expand_var(t_exp *w, t_string *d, const char *v)
{
	t_exp_flag f;

	if (!v)
		return ;
	f = w->flags;
	w->flags &= EXP_WILDCARD;
	exp_word(w, d, v);
	w->flags = f;
}

const char	*exp_var(t_exp *w, t_string *d, const char *s)
{
	size_t n;
	size_t i;

	n = *s == '?' ? 1 : env_varlen(s);
	if (n && (w->flags & EXP_VAR))
		expand_var(w, d, env_getn(w->env, s, n));
	else
	{
		ft_string_push_back(d, '$');
		i = 0;
		while (i < n)
			ft_string_push_back(d, s[i++]);
	}
	return (s + n);
}
