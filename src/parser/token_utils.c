/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:37:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 13:55:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "utils.h"

t_token	*token(t_list *element)
{
	return (element ? element->content : NULL);
}

void	token_clear(t_token *t)
{
	if (t->type != TOKEN_WORD && t->type != TOKEN_MULTILINE)
		return ;
	if (t->type == TOKEN_WORD)
		ft_delete(t->value);
	free(t);
}

void	token_print(t_token *t)
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
