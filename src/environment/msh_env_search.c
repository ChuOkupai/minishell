/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:48:24 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 14:51:53 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*msh_env_search(t_list *env, const char *name)
{
	size_t n;

	n = ft_strlen(name);
	while (env && ft_strncmp(env->content, name, n))
		env = env->next;
	return (env);
}
