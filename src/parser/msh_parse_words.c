/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 20:47:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/14 19:29:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"
#include "parser.h"
#include "utils.h"

static size_t	parse_variable(char **dst, char **src, t_list *env)
{
	char		*s;
	size_t		i;
	char		tmp;
	const char	*value;

	s = *src + 1;
	i = 0;
	while (s[i] && ft_isalnum(s[i]) && !ft_strchr("\"'\\$", s[i]))
		++i;
	tmp = s[i];
	s[i] = '\0';
	value = i ? msh_env_get(env, s) : NULL;
	s[i] = tmp;
	*src = s + i;
	if ((i = value ? ft_strlen(value) : 0) && *dst)
		*dst = (char *)ft_memcpy(*dst, value, i) + i;
	return (i);
}

static size_t	parse_single_quote(char **dst, char **src)
{
	char	*s;
	size_t	n;

	s = *src + 1;
	if ((n = ft_strchr(s, '\'') - s) && *dst)
		*dst = (char *)ft_memcpy(*dst, s, n) + n;
	*src = s + n + 1;
	return (n);
}

static size_t	parse_word(char *d, char *s, t_list *env)
{
	bool	dq;
	size_t	n;

	dq = false;
	n = 0;
	while (*s)
		if (!dq && *s == '\'')
			n += parse_single_quote(&d, &s);
		else if (*s == '$')
			n += parse_variable(&d, &s, env);
		else if (*s == '"')
		{
			dq = !dq;
			++s;
		}
		else
		{
			if (*s == '\\' && s[1])
				++s;
			if (d)
				*d++ = *s;
			++n;
			++s;
		}
	return (n);
}

void			msh_parse_words(t_list *l, t_list *env)
{
	t_token	*t;
	char	*d;

	while (l)
	{
		if ((t = msh_token(l))->type == TOKEN_WORD)
		{
			t->size = parse_word(NULL, t->value, env);
			if (!(d = malloc((t->size + 1) * sizeof(char))))
				msh_abort();
			d[t->size] = '\0';
			parse_word(d, t->value, env);
			free(t->value);
			t->value = d;
		}
		l = l->next;
	}
}
