/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_abspath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:09:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:44:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "env.h"

static char	*join(const char *bin, const char *path, size_t n)
{
	size_t	m;
	char	*s;

	m = ft_strlen(bin);
	s = ft_malloc((n + m + 2) * sizeof(char));
	ft_memcpy(s, path, n);
	s[n] = '/';
	ft_memcpy(s + n + 1, bin, m);
	s[n + m + 1] = '\0';
	return (s);
}

char		*env_abspath(const t_env *env, const char *bin)
{
	const char	*path;
	char		*s;
	size_t		n;
	size_t		m;
	struct stat	buf;

	path = env_get(env, "PATH");
	if (ft_strisempty(bin) || ft_strisempty(path))
		return (NULL);
	if (ft_strchr(bin, '/'))
		return ((char*)bin);
	n = ft_strlen(path);
	while ((s = ft_memchr(path, ':', n)))
	{
		m = s - path;
		s = join(bin, path, m);
		if (!stat(s, &buf))
			return (s);
		ft_free(s);
		++m;
		path += m;
		n -= m;
	}
	return (NULL);
}
