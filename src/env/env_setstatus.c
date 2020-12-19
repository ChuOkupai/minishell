/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setstatus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:32:12 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:44:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int	set(t_status *s, int value)
{
	if (value != s->value)
		s->buf = ft_free(s->buf);
	s->value = value;
	return (value);
}

int			env_setstatus(t_env *env, int value)
{
	return (set(&env->status, value));
}
