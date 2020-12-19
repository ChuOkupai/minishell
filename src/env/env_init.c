/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:44:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"

void	env_init(t_env *env, char **env_array)
{
	size_t	i;
	char	*pwd;

	env->size = ft_memsize((void**)env_array);
	env->capacity = env->size + ENV_BUFSIZE;
	env->array = ft_malloc((env->capacity + 1) * sizeof(char*));
	i = 0;
	while (i < env->size)
	{
		env->array[i] = ft_strdup(env_array[i]);
		++i;
	}
	ft_bzero(env->array + i, sizeof(char*) * (env->capacity - i + 1));
	if ((pwd = msh_getcwd()))
		env_set(env, "PWD", pwd);
	ft_free(pwd);
}
