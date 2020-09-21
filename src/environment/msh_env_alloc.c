/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/21 18:07:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "const.h"
#include "environment.h"
#include "utils.h"

void	*msh_env_clear(t_env *e)
{
	if (!e)
		return (NULL);
	ft_list_clear(&e->list, &free);
	ft_memdel(e->array);
	ft_memdel(e->status_val);
	ft_memdel(e->pwd);
	return (NULL);
}

t_env	*msh_env_new(char **env)
{
	t_env	*e;
	char	*s;

	if (!(e = ft_calloc(1, sizeof(t_env))))
		return (NULL);
	s = NULL;
	while (*env && (s = ft_strdup(*env)) && ft_list_push(&e->list, s))
		++env;
	if (*env || msh_env_set(e, "SHELL", MSH) < 0 ||
	!(e->array = (char **)ft_list_to_array(e->list)))
	{
		ft_memdel(s);
		e = msh_env_clear(e);
		msh_perror("warning - Could not load environment");
	}
	e->list = ft_list_rev(e->list);
	return (e);
}