/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_getcwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:39:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 16:43:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "libft.h"

char	*msh_getcwd(void)
{
	static size_t	n = 128;
	char			*buf;

	buf = ft_malloc(n * sizeof(char));
	while (!getcwd(buf, n))
	{
		if (errno != ERANGE)
			return (ft_free(buf));
		errno = 0;
		buf = ft_realloc(buf, n, 2 * n, false);
		n *= 2;
	}
	return (buf);
}
