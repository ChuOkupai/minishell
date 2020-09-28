/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:56:58 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 17:05:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"

void	msh_env_clear(t_env *env)
{
	ft_list_clear(&env->list, &free);
	ft_memdel(env->array);
	ft_memdel(env->status_val);
}
