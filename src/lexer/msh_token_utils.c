/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:37:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 20:06:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer.h"
#include "utils.h"

t_token	*msh_token(t_list *element)
{
	return (element ? element->content : NULL);
}

void	msh_token_clear(t_token *t)
{
	if (t->type != TOKEN_WORD)
		return ;
	free(t->value);
	free(t);
}

t_token	*msh_token_find(const char *s)
{
	static const t_token	lexer[] = {
		{ TOKEN_LEFT_PAR, "(", 1 },
		{ TOKEN_RIGHT_PAR, ")", 1 },
		{ TOKEN_PIPE, "|", 1 },
		{ TOKEN_SEMICOLON, ";", 1 },
		{ TOKEN_REDIRECT, "<", 1 },
		{ TOKEN_REDIRECT, ">", 1 },
		{ TOKEN_REDIRECT, "<<", 2 },
		{ TOKEN_REDIRECT, ">>", 2 },
		{ TOKEN_LOGICAL_OP, "&&", 2 },
		{ TOKEN_LOGICAL_OP, "||", 2 }
	};
	size_t					i;

	i = sizeof(lexer) / sizeof(*lexer);
	while (i--)
		if (!ft_memcmp(s, lexer[i].value, lexer[i].size))
			return ((t_token *)lexer + i);
	return (NULL);
}

t_token	*msh_token_new(char *value, size_t size)
{
	t_token *t;

	if (!(t = malloc(sizeof(t_token))) || !value)
		msh_abort("parser");
	t->type = TOKEN_WORD;
	t->value = value;
	t->size = size;
	return (t);
}

void	msh_token_print(t_token *t)
{
	ft_printf((t->type == TOKEN_WORD ? "WORD(%s)" : "%s"), t->value);
}
