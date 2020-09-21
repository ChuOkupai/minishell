/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:43:09 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/21 20:07:59 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"
#include "const.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int			msh_pwd(char **argv)
{
	char	*buf;
	int		size;

	size = 128;
	if (argv[1] && argv[1][0] == '-' && argv[1][1] &&
		(argv[1][2] || argv[1][1] != '-'))
		return (msh_perrorr(1, "%s: %s: invalid option\n", argv[0], argv[1]));
	if (!(buf = malloc(sizeof(char) * size)))
		return (1);
	buf = getcwd(buf, size);
	ft_putstr(buf);
	return (0);
}
