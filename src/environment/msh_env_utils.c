/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/21 18:32:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"

static t_list	*search(t_list *env, const char *name)
{
	size_t n;

	n = ft_strlen(name);
	while (env && (ft_memcmp(env->content, name, n) ||
	((char *)env->content)[n] != '='))
		env = env->next;
	return (env);
}

const char		*msh_env_get(t_env *env, const char *name)
{
	t_list *e;

	if (!ft_strcmp(name, "?"))
	{
		if (!env->status_val)
			env->status_val = ft_itoa(env->status);
		return (env->status_val);
	}
	else
		e = search(env->list, name);
	return (e ? (const char *)(e->content) + ft_strlen(name) + 1 : NULL);
}

int				msh_env_set(t_env *env, const char *name, const char *value)
{
	void	*s;
	t_list	*l;

	if (!(s = ft_strjoin3(name, "=", value)))
		return (-1);
	if ((l = search(env->list, name)))
	{
		ft_memdel(l->content);
		l->content = s;
	}
	else if (!ft_list_push(&env->list, s))
	{
		ft_memdel(s);
		return (-1);
	}
	ft_memdel(env->array);
	env->array = (char **)ft_list_to_array(env->list);
	return (0);
}

void			msh_env_setstatus(t_env *env, int status)
{
	if (status != env->status)
		env->status_val = ft_memdel(env->status_val);
	env->status = status;
}

void			msh_env_unset(t_env *env, const char *name)
{
	t_list *l;

	if (!(l = search(env->list, name)))
		return ;
	ft_list_remove_one(&env->list, l->content, &ft_compare_pointer, &free);
	ft_memdel(env->array);
	env->array = (char **)ft_list_to_array(env->list);
}
