/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:29:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/12 17:51:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

static t_exp_func	find(const char c, const t_exp_pair *pair, size_t n)
{
	if (!n)
		return (NULL);
	if (c == pair->c)
		return (pair->function);
	return (find(c, pair + 1, n - 1));
}

static t_exp_func	get_exp_func(const char c)
{
	static const t_exp_pair	lexer[] = {
		{ '\\', &exp_backslash },
		{ '"', &exp_dquote },
		{ '\'', &exp_quote },
		{ '$', &exp_var },
		{ '*', &exp_wildcard }
	};

	return (find(c, lexer, sizeof(lexer) / sizeof(*lexer)));
}

void				exp_word(t_exp *w, t_string *d, const char *s)
{
	t_exp_func f;

	while (*s)
		if ((f = get_exp_func(*s)))
			s = f(w, d, s + 1);
		else
			ft_string_push_back(d, *s++);
}
