/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:59:50 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/26 18:28:51 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"
#include "utils.h"

int		exit(char **argv, t_shell *shell)
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
	else if (!(*ft_strwhile(argv[1], ft_isdigit)))
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
