/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 17:06:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	env_init(t_env *env, char **env_array)
{
	char *s;

	while (*env_array && (s = ft_strdup(*env_array)))
	{
		if (!ft_list_push(&env->list, ft_list_new(s)))
		{
			ft_delete(s);
			break ;
		}
		++env_array;
	}
	env->list = ft_list_rev(env->list);
	env_set(env, "SHELL", "minishell");
}
