/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline_set_histsize.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:52:21 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 21:47:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "readline.h"

void	msh_readline_set_histsize(t_readline *r, size_t size)
{
	t_history	*h;
	t_list		*l;

	h = &r->history;
	if (h->size > size)
	{
		l = size ? ft_list_at(h->list, size - 1) : NULL;
		ft_list_clear((size ? &l->next : &h->list), &free);

	}
	h->size = size;
}
