/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:29:02 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/15 12:46:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

static bool	wmatch(const char *s, const char *w, const t_list *e)
{
	if (*w)
	{
		if (*s != *w)
			return (false);
		++w;
	}
	else if (!e)
		return (!*s);
	else if (token(e->content)->type == TOKEN_WORD)
		return (wmatch(s, token(e->content)->value, e->next));
	else
	{
		if (wmatch(s, w, e->next))
			return (true);
		if (!*s)
			return (false);
	}
	return (wmatch(s + 1, w, e));
}

bool		wcexp_match(const char *s, const t_list *expr)
{
	return (wmatch(s, "", expr));
}
