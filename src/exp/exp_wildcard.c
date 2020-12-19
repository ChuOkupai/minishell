/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_wildcard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:20:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/12 19:07:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"
#include "token.h"

const char	*exp_wildcard(t_exp *w, t_string *d, const char *s)
{
	if (w->flags & EXP_WILDCARD)
	{
		wcexp_flush(&w->wc, d);
		wcexp_push_sep(&w->wc);
	}
	ft_string_push_back(d, '*');
	while (*s == '*')
		ft_string_push_back(d, *s++);
	w->wc.i = ft_string_length(d);
	return (s);
}
