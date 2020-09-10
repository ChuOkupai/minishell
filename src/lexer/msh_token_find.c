/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:48:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/09 21:01:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_token	*search(const char *s, const t_token *lexer, size_t i)
{
	while (i--)
		if (!ft_memcmp(s, lexer[i].value, lexer[i].size))
			return ((t_token *)lexer + i);
	return (NULL);
}

t_token			*msh_token_find(const char *s)
{
	static const t_token lexer[] = {
		{ TOKEN_LEFT_PARENTHESIS, "(", 1 },
		{ TOKEN_RIGHT_PARENTHESIS, ")", 1 },
		{ TOKEN_PIPE, "|", 1 },
		{ TOKEN_SEMICOLON, ";", 1 },
		{ TOKEN_REDIR, "<", 1 },
		{ TOKEN_REDIR, ">", 1 },
		{ TOKEN_REDIR, "<<", 2 },
		{ TOKEN_REDIR, ">>", 2 },
		{ TOKEN_LOGICAL_OP, "&&", 2 },
		{ TOKEN_LOGICAL_OP, "||", 2 }
	};

	return (search(s, lexer, sizeof(lexer) / sizeof(*lexer)));
}
