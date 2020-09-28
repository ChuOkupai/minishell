/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:36:33 by user42            #+#    #+#             */
/*   Updated: 2020/09/28 17:26:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "libft.h"

char	*msh_path(char *name, t_env *env)
{
	t_list			*lst_path;
	t_list			*ptr;
	char			*pathname;
	struct stat		statbuf;

	if (stat(name, &statbuf) == 0)
		return (name);
	lst_path = ft_list_split(msh_env_get(env, "PATH"), ":");
	ptr = lst_path;
	while (ptr)
	{
		pathname = ft_strjoin3(ptr->content, "/", name);
		if (stat(pathname, &statbuf) == 0)
		{
			ft_list_clear(&lst_path, &free);
			return (pathname);
		}
		free(pathname);
		ptr = ptr->next;
	}
	ft_list_clear(&lst_path, &free);
	return (NULL);
}
