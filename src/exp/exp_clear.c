/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:47:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 17:40:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

void	exp_clear(t_exp *w)
{
	wcexp_clear(&w->wc);
	w->dst = ft_free(w->dst);
	ft_list_clear(&w->args, (t_gfunction) & ft_free);
}
