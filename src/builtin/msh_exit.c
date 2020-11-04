/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:59:50 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/04 16:37:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"

int		msh_exit(char **argv, t_shell *shell)
{
	unsigned char	ret;

	if (!argv[1])
	{
		ret = 0;
		shell->keep = false;
	}
	else if (argv[1] && argv[2])
	{
		msh_perror("%s : too many arguments", argv[0]);
		return (1);
	}
	else if (*ft_strwhile(argv[1], ft_isdigit))
	{
		msh_perror("%s : %s : numeric argument required", argv[0], argv[1]);
		ret = 255;
		shell->keep = false;
	}
	else
	{
		ret = (unsigned char)ft_atoi(argv[1]);
		shell->keep = false;
	}
	return (ret);
}
