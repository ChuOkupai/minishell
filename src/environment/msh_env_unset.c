/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:06:48 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 14:52:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"
#include "utils.h"

static int	cmp(const void *a, const void *b)
{
	return (a != b);
}

void		msh_env_unset(t_list **env, const char *name)
{
	t_list *l;

	if ((l = msh_env_search(*env, name)))
		ft_list_remove_if(env, l->content, &cmp, &free);
}
