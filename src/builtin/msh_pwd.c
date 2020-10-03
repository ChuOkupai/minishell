/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:43:09 by gdinet            #+#    #+#             */
/*   Updated: 2020/10/01 11:35:17 by user42           ###   ########.fr       */
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

	if (argv[1] && argv[1][0] == '-' && argv[1][1] &&
		(argv[1][2] || argv[1][1] != '-'))
		return (msh_perrorr(1, "%s: %s: invalid option", argv[0], argv[1]));
	if (!(buf = malloc(sizeof(char) * shell->pwd.size)))
		return (1);
	buf = getcwd(buf, shell->pwd.size);
	ft_putendl(buf);
	free(buf);
	return (0);
}
