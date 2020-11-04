/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:43:09 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/04 16:31:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"
#include "utils.h"

int		msh_pwd(char **argv, t_shell *shell)
{
	char	*buf;

	if (argv[1] && argv[1][0] == '-' && argv[1][1] &&
		(argv[1][2] || argv[1][1] != '-'))
		return (msh_perrorr(1, "%s: %s: invalid option", argv[0], argv[1]));
	if (!(buf = ft_new(sizeof(char) * shell->pwd.size)))
		return (1);
	buf = getcwd(buf, shell->pwd.size);
	ft_putendl(buf);
	ft_delete(buf);
	return (0);
}
