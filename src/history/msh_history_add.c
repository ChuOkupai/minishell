/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_history_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:20:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 17:16:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "readline.h"

static void	history_del_last(t_history *h)
{
	t_list *prev;
	t_list *l;

	if (!--h->size)
		ft_list_clear(&h->list, &free);
	else
	{
		prev = ft_list_at(h->list, h->size - 1);
		l = prev->next;
		prev->next = NULL;
		ft_list_pop(&l, &free);
	}
}

int			msh_history_add(t_history *h, const char *s)
{
	char *s2;

	if (!h->histsize || !s)
		return (0);
	else if (!(s2 = ft_strdup(s)) || !ft_list_push(&h->list, s2))
	{
		ft_memdel(s2);
		return (-1);
	}
	if (h->size == h->histsize)
		history_del_last(h);
	++h->size;
	return (0);
}
