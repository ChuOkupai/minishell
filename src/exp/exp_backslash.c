/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_backslash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:21:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/12 18:30:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

const char	*exp_backslash(t_exp *w, t_string *d, const char *s)
{
	if (!(w->flags & EXP_BACKSLASH))
		ft_string_push_back(d, '\\');
	if (*s)
		ft_string_push_back(d, *s++);
	return (s);
}
