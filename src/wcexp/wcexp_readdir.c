/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp_readdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:42:29 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/16 15:17:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "utils.h"
#include "wcexp.h"

t_list	*wcexp_readdir(const char *path, bool hidden)
{
	t_list			*l;
	DIR				*dir;
	struct dirent	*ent;

	l = NULL;
	dir = opendir(path);
	if (!dir)
		return (l);
	while ((ent = readdir(dir)))
		if (hidden || *ent->d_name != '.')
			ft_list_push(&l, ft_list_new(ft_strdup(ent->d_name)));
	closedir(dir);
	return (l);
}
