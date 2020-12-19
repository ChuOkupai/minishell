/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:24:58 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:51:53 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

const char	*exp_quote(t_exp *w, t_string *d, const char *s)
{
	if (*s == '\'')
		return (s + 1);
	ft_string_push_back(d, *s);
	return (exp_quote(w, d, s + 1));
}
