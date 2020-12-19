/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:35:59 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/09 20:13:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static const char	*g_lexer[REDIR_SIZE] = { "<", "<<", ">", ">>" };

void		redir_print(const t_redir *r)
{
	ft_printf("%s %s", g_lexer[r->op], (r->path ? r->path : r->raw_path));
}

t_redir_op	redir_op(const char *value)
{
	size_t i;

	i = REDIR_SIZE;
	while (i--)
		if (!ft_strcmp(value, g_lexer[i]))
			return (i);
	return (-1);
}
