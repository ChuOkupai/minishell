/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 14:50:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "utils.h"

t_list		*msh_env_copy(char **env)
{
	t_list	*l;
	char	*s;

	l = NULL;
	while (*env)
		if (!(s = ft_strdup(*env++)) || !ft_list_push(&l, ft_list_new(s)))
			msh_abort();
	return (ft_list_rev(l));
}
