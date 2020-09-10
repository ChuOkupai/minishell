/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 14:51:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

const char	*msh_env_get(t_list *env, const char *name)
{
	env = msh_env_search(env, name);
	return (env ? (const char *)(env->content) + ft_strlen(name) + 1 : NULL);
}
