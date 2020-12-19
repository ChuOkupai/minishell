/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:14:10 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 17:39:52 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "wcexp.h"

void	wcexp_clear(t_wcexp *w)
{
	ft_list_clear(&w->l, (t_gfunction) & token_clear);
}
