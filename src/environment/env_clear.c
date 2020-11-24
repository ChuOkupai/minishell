/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:56:58 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:52:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"

void	env_clear(t_env *env)
{
	ft_list_clear(&env->list, &free);
	ft_delete(env->array);
	ft_delete(env->status_val);
}
