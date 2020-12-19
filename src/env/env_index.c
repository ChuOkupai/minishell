/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:52:23 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/15 18:55:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

size_t	env_index(const t_env *env, const char *name, size_t n)
{
	char	**t;
	size_t	i;

	t = env->array;
	i = 0;
	while (t[i] && (ft_memcmp(t[i], name, n) || (t[i][n] && t[i][n] != '=')))
		++i;
	return (i);
}
