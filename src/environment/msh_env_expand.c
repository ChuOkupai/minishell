/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:33:18 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 16:46:23 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "const.h"
#include "environment.h"

static size_t	parse_variable(char **dst, char **src, t_env *env)
{
	char		*s;
	size_t		i;
	const char	*value;

	s = *src + 1;
	i = 0;
	if (s[i] == '?')
		++i;
	else
		while (s[i] && (ft_isalnum(s[i]) || s[i] == '_') &&
		!ft_strchr(MSH_STOKEN, s[i]))
			++i;
	value = i ? msh_env_getn(env, s, i) : "$";
	*src = s + i;
	if ((i = ft_strlen(value)) && *dst)
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

static size_t	parse_word(char *d, char *s, t_env *env)
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
			if (*s == '\\' && s[1] && ft_strchr(MSH_STOKEN, s[1]))
				++s;
			if (d)
				*d++ = *s;
			++n;
			++s;
		}
	return (n);
}

char			*msh_env_expand(t_env *env, char *s)
{
	char	*d;
	size_t	n;

	n = parse_word(NULL, (char *)s, env);
	if (!(d = malloc((n + 1) * sizeof(char))))
		return (NULL);
	d[n] = '\0';
	parse_word(d, (char *)s, env);
	return (d);
}
