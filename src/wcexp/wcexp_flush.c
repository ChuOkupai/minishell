/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:13:02 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/12 18:56:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"
#include "token.h"

void	wcexp_flush(t_wcexp *w, t_string *d)
{
	t_token *t;

	if (w->i == ft_string_length(d))
		return ;
	t = token_new(TOKEN_WORD, ft_strdup(d->buf + w->i));
	ft_list_push(&w->l, ft_list_new(t));
}
