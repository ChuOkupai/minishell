/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/15 13:42:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const.h"
#include "environment.h"

void	msh_env_init(t_env *env, char **env_array)
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
	msh_env_set(env, "SHELL", MSH);
}
