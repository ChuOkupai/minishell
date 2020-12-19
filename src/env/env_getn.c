/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/15 15:50:00 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	*getstatus(const t_status *s)
{
	if (!s->buf)
		((t_status*)s)->buf = ft_itoa(s->value);
	return (s->buf);
}

const char	*env_getn(const t_env *env, const char *name, size_t n)
{
	size_t	i;
	bool	eq;

	if (!n)
		return (NULL);
	if (!ft_strncmp(name, "?", n))
		return (getstatus(&env->status));
	i = env_index(env, name, n);
	if (i < env->size)
	{
		eq = env->array[i][n] == '=';
		return (env->array[i] + n + eq);
	}
	return (NULL);
}
