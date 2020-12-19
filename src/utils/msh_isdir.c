/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_isdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:08:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/04 20:09:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>

bool	msh_isdir(const char *path)
{
	struct stat	buf;

	return (!stat(path, &buf) && !!S_ISDIR(buf.st_mode));
}
