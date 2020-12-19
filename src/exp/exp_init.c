/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:47:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 16:57:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

void	exp_init(t_exp *w, const t_env *env, t_exp_flag flags)
{
	w->dst = NULL;
	w->args = NULL;
	w->env = env;
	w->flags = flags;
}
