/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:52:21 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 15:19:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "readline.h"

void	history_resize(t_history *h, size_t size)
{
	t_list *l;

	if (h->size > size)
	{
		l = size ? ft_list_at(h->list, size - 1) : NULL;
		ft_list_clear((size ? &l->next : &h->list), &free);
		h->size -= size;
	}
	h->histsize = size;
}
