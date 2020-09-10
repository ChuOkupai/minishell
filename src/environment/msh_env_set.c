/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:36:16 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 14:52:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "utils.h"

const char		*msh_env_set(t_list **env, const char *name, const char *value)
{
	void	*s;
	t_list	*l;

	if (!(s = ft_strjoin3(name, "=", value)))
		msh_abort();
	if ((l = msh_env_search(*env, name)))
	{
		ft_memdel(l->content);
		l->content = s;
	}
	else if (!ft_list_push(env, ft_list_new(s)))
		msh_abort();
	return (NULL);
}
