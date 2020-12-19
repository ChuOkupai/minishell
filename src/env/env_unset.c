/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:44:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

void		env_unset(t_env *env, const char *name)
{
	size_t i;

	i = env_index(env, name, ft_strlen(name));
	if (i == env->size)
		return ;
	env->array[i] = ft_free(env->array[i]);
	if (--env->size > 0 && i != env->size)
		swap(env->array + i, env->array + env->size);
}
