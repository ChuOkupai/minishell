/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:56:58 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/15 13:41:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"

void	msh_env_clear(t_env *env)
{
	ft_list_clear(&env->list, &free);
	ft_delete(env->array);
	ft_delete(env->status_val);
}
