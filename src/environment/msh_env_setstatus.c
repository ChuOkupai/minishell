/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_setstatus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:32:12 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 16:08:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	msh_env_setstatus(t_env *env, int value)
{
	if (value != env->status)
		env->status_val = ft_memdel(env->status_val);
	env->status = value;
}
