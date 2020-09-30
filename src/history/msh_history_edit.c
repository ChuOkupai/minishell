/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_history_edit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:04:40 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 17:18:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "history.h"

int	msh_history_edit(t_history *h, const char *s, size_t i)
{
	char	*s2;
	t_list	*l;

	if (!h->histsize || !s || i >= h->size)
		return (0);
	else if (!(s2 = ft_strdup(s)))
		return (-1);
	l = ft_list_at(h->list, i);
	free(l->content);
	l->content = s2;
	return (0);
}
