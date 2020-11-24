/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:59:50 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/24 17:11:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const.h"
#include "shell.h"
#include "utils.h"

static int	success(t_shell *shell, t_u8 value)
{
	shell->keep = false;
	return (value);
}

int			builtin_exit(char **argv, t_shell *shell)
{
	if (!argv[1])
		return (success(shell, 0));
	if (argv[1] && argv[2])
		return (msh_perrorr(1, MSH_ERR "%s : too many arguments", argv[0]));
	if (!*ft_strwhile(argv[1], ft_isdigit))
		return (success(shell, ft_atoi(argv[1])));
	msh_perror("%s : %s : numeric argument required", argv[0], argv[1]);
	return (success(shell, 255));
}
