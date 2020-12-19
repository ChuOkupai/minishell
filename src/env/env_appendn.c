/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_appendn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:22:57 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:44:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_appendn(t_env *env, const char *name, const char *value, size_t n)
{
	const char	*old_value;
	char		*s;

	old_value = env_getn(env, name, n);
	if (old_value)
	{
		s = ft_strjoin(old_value, value);
		env_setn(env, name, s, n);
		ft_free(s);
	}
	else
		env_setn(env, name, value, n);
}
