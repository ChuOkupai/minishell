/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:36:33 by gdinet            #+#    #+#             */
/*   Updated: 2020/10/03 11:01:33 by gdinet           ###   ########.fr       */
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
