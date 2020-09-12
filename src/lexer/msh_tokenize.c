/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:24:41 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/12 16:49:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "utils.h"

/*
** Returns the next token.
** Returns NULL on unclosed quoted string.
*/

static t_token	*next_token(const char *s)
{
	char	*s2;
	size_t	n;

	s2 = (char *)s--;
	while (*(++s) && !ft_isspace(*s) && !msh_token_find(s))
		if (*s == '\\')
			s += s[1] != '\0';
		else if (*s == '\'' || *s == '"')
		{
			while ((s = ft_strchr(s + 1, *s)) && s[-1] == '\\')
				continue ;
			if (!s)
				return (NULL);
		}
	n = s - s2;
	return (n ? msh_token_new(ft_strndup(s2, n), n) : msh_token_find(s));
}

t_list			*msh_tokenize(const char *s)
{
	t_list	*l;
	t_token	*t;

	l = NULL;
	while (*(s = ft_strwhile(s, &ft_isspace)))
		if (!(t = next_token(s)))
		{
			msh_perror("unsupported multiline quoted string");
			ft_list_clear(&l, (t_gfunction) & msh_token_clear);
			break ;
		}
		else if (!ft_list_push(&l, ft_list_new(t)))
			msh_abort();
		else
			s += t->size;
	return (ft_list_rev(l));
}
