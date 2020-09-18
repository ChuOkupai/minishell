/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:24:41 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 12:48:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "utils.h"

/*
** Tries to find a token from the lexer in the given string s.
** Returns the address of the static token if found in the lexer.
** Operator precedence for TOKEN_LOGICAL_OP is determined by their position.
** Returns NULL if the token is of type TOKEN_WORD.
*/

static t_token	*find_in_lexer(const char *s)
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
		{ TOKEN_LOGICAL_OP, "||", 2 },
		{ TOKEN_LOGICAL_OP, "&&", 2 }
	};
	size_t					i;

	i = sizeof(lexer) / sizeof(*lexer);
	while (i--)
		if (!ft_memcmp(s, lexer[i].value, lexer[i].size))
			return ((t_token *)lexer + i);
	return (NULL);
}

/*
** Allocates memory for a new dynamic token.
** Returns NULL on error.
*/

static t_token	*new_token(t_token_type type, char *value)
{
	t_token *t;

	if (!value || !(t = malloc(sizeof(t_token))))
		return (NULL);
	t->type = type;
	t->value = value;
	t->size = ft_strlen(value);
	return (t);
}

/*
** Returns the next token.
** Returns NULL on unclosed quoted string.
*/

static t_token	*next_token(const char *s)
{
	char	*s2;
	t_token	*t;
	size_t	n;

	s2 = (char *)s--;
	while (*(++s) && !ft_isspace(*s) && !(t = find_in_lexer(s)))
		if (*s == '\\')
			s += s[1] != '\0';
		else if (*s == '\'')
		{
			if (!(s = ft_strchr(s + 1, '\'')))
				return (new_token(TOKEN_MULTILINE, ft_strdup(s2)));
		}
		else if (*s == '"')
		{
			while ((s = ft_strchr(s + 1, *s)) && s[-1] == '\\')
				continue ;
			if (!s)
				return (new_token(TOKEN_MULTILINE, ft_strdup(s2)));
		}
	return ((n = s - s2) ? new_token(TOKEN_WORD, ft_strndup(s2, n)) : t);
}

t_list			*msh_tokenize(const char *s)
{
	t_list	*l;
	t_token	*t;

	l = NULL;
	while (*(s = ft_strwhile(s, &ft_isspace)))
		if (!(t = next_token(s)) || !ft_list_push(&l, t))
		{
			ft_memdel(t);
			ft_list_clear(&l, (t_gfunction) & msh_token_clear);
			break ;
		}
		else
			s += t->size;
	return (ft_list_rev(l));
}
