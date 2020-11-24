/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:53:23 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"

static t_list	*search(t_list *env, const char *name, size_t n)
{
	while (env && (ft_memcmp(env->content, name, n) ||
	((char *)env->content)[n] != '='))
		env = env->next;
	return (env);
}

const char		*env_get(t_env *env, const char *name)
{
	return (env_getn(env, name, ft_strlen(name)));
}

const char		*env_getn(t_env *env, const char *name, size_t n)
{
	t_list	*e;
	size_t	m;

	if (!ft_strcmp(name, "?"))
	{
		if (!env->status_val)
			env->status_val = ft_itoa(env->status);
		return (env->status_val);
	}
	else
	{
		m = ft_strlen(name);
		n = n > m ? m : n;
		e = search(env->list, name, n);
	}
	return (e ? (const char *)(e->content) + n + 1 : NULL);
}

void			env_set(t_env *env, const char *name, const char *value)
{
	void	*s;
	t_list	*l;

	if (!(s = ft_strjoin3(name, "=", value)))
		return ;
	if ((l = search(env->list, name, ft_strlen(name))))
	{
		ft_delete(l->content);
		l->content = s;
	}
	else if (!ft_list_push(&env->list, ft_list_new(s)))
		ft_delete(s);
	ft_delete(env->array);
	env->array = (char **)ft_list_to_array(env->list);
}

void			env_unset(t_env *env, const char *name)
{
	t_list *l;

	if (!(l = search(env->list, name, ft_strlen(name))))
		return ;
	free(ft_list_remove_one(&env->list, l->content));
	ft_delete(env->array);
	env->array = (char **)ft_list_to_array(env->list);
}
