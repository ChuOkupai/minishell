/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:49:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 21:56:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "readline.h"

static void	history_add(t_history *h, char *s)
{
	t_list *l;

	if (h->size == h->histsize)
	{
		l = ft_list_at(h->list, h->size--);
		ft_list_clear(&l, &free);
	}
	ft_list_push(&h->list, s);
	++h->size;
}

char		*msh_readline(t_readline *r, const char *prompt)
{
	char *s;

	if (prompt)
		ft_putstr(prompt);
	if (ft_getline(&s, r->stream) == FT_EOF && ft_ferror(r->stream))
		s = ft_memdel(s);
	else if (r->history.histsize && s && *ft_strwhile(s, &ft_isspace))
		history_add(&r->history, ft_strdup(s));
	return (s);
}
