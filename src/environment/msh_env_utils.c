/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:21:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 19:47:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"
#include "utils.h"

static t_list	*search(t_list *env, const char *name)
{
	size_t n;

	n = ft_strlen(name);
	while (env && (ft_memcmp(env->content, name, n) ||
	((char *)env->content)[n] != '='))
		env = env->next;
	return (env);
}

const char		*msh_env_get(t_list *env, const char *name)
{
	env = search(env, name);
	return (env ? (const char *)(env->content) + ft_strlen(name) + 1 : NULL);
}

void			msh_env_set(t_list **env, const char *name, const char *value)
{
	void	*s;
	t_list	*l;

	if (!(s = ft_strjoin3(name, "=", value)))
		msh_abort("setenv");
	else if ((l = search(*env, name)))
	{
		ft_memdel(l->content);
		l->content = s;
	}
	else if (!ft_list_push(env, ft_list_new(s)))
		msh_abort("setenv");
}

void			msh_env_unset(t_list **env, const char *name)
{
	t_list *l;

	if ((l = search(*env, name)))
		ft_list_remove_one(env, l->content, &msh_compare_pointer, &free);
}
