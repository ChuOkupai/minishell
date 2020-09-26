/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:43:09 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/26 15:17:39 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"
#include "const.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int		msh_pwd(char **argv, t_shell *shell)
{
	char	*buf;
	int		size;

	(void)shell;
	size = 128;
	if (argv[1] && argv[1][0] == '-' && argv[1][1] &&
		(argv[1][2] || argv[1][1] != '-'))
		return (msh_perrorr(1, MSH_INVALID_OPTION, argv[0], argv[1]));
	if (!(buf = malloc(sizeof(char) * size)))
		return (1);
	buf = getcwd(buf, size);
	ft_putendl(buf);
	free(buf);
	return (0);
}
