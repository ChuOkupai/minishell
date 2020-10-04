/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:37:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/04 16:16:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "utils.h"

t_token	*msh_token(t_list *element)
{
	return (element ? element->content : NULL);
}

void	msh_token_clear(t_token *t)
{
	if (t->type != TOKEN_WORD && t->type != TOKEN_MULTILINE)
		return ;
	if (t->type == TOKEN_WORD)
		ft_memdel(t->value);
	free(t);
}

void	msh_token_print(t_token *t)
{
	const char *format;

	if (t->type == TOKEN_WORD)
		format = "WORD(%s)";
	else if (t->type == TOKEN_MULTILINE)
		format = "MULTILINE(%s)";
	else
		format = "%s";
	ft_printf(format, t->value);
}
