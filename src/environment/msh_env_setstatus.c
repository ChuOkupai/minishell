/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_setstatus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:32:12 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/15 13:41:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int		msh_env_setstatus(t_env *env, int value)
{
	if (value != env->status)
		env->status_val = ft_delete(env->status_val);
	env->status = value;
	return (value);
}
