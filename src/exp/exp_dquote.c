/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_dquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:27:56 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/12 18:42:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

static const char	*accept(t_exp *w, t_string *d, const char *s)
{
	if (*s == '"')
		return (s + 1);
	if (*s == '$')
		return (exp_dquote(w, d, exp_var(w, d, s + 1)));
	if (*s == '\\' && !ft_strchr("$\"", *++s))
		ft_string_push_back(d, '\\');
	ft_string_push_back(d, *s++);
	return (accept(w, d, s));
}

static const char	*ignore(t_string *d, const char *s)
{
	ft_string_push_back(d, '"');
	while (*s != '"')
	{
		if (*s == '\\')
			ft_string_push_back(d, *s++);
		ft_string_push_back(d, *s++);
	}
	ft_string_push_back(d, '"');
	return (s + 1);
}

const char			*exp_dquote(t_exp *w, t_string *d, const char *s)
{
	return (w->flags & EXP_DQUOTE ? accept(w, d, s) : ignore(d, s));
}
