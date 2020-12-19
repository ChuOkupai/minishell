/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:28:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/15 15:42:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	*join(const char *name, const char *value, size_t n)
{
	bool	eq;
	size_t	n2;
	char	*s;

	eq = !!value;
	n2 = ft_strlen(value);
	s = ft_malloc((n + n2 + eq + 1) * sizeof(char));
	ft_memcpy(s, name, n);
	ft_memcpy(s + n + eq, value, n2);
	if (eq)
		s[n] = '=';
	s[n + n2 + eq] = '\0';
	return (s);
}

void		env_setn(t_env *env, const char *name, const char *value, size_t n)
{
	size_t i;

	if (!n)
		return ;
	i = env_index(env, name, n);
	if (i < env->size)
		ft_free(env->array[i]);
	else if (env->size++ == env->capacity)
	{
		env->capacity += ENV_BUFSIZE;
		env->array = ft_realloc(env->array, sizeof(char *) * i,
		sizeof(char *) * (env->capacity + 1), true);
	}
	env->array[i] = join(name, value, n);
}
