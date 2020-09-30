/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_history_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:42:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 16:44:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const.h"
#include "history.h"

void	msh_history_init(t_history *h)
{
	h->list = NULL;
	h->size = 0;
	h->histsize = MSH_HISTORY_SIZE;
}
