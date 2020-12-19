/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:49:41 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/15 17:39:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	is_n(int c)
{
	return (c == 'n');
}

static void	print(char **s, bool put_space)
{
	if (!*s)
		return ;
	if (put_space)
		ft_putchar(' ');
	ft_putstr(*s);
	print(s + 1, true);
}

int			builtin_echo(char **av, t_shell *s)
{
	bool option_n;

	(void)s;
	option_n = false;
	while (*(++av) && **av == '-')
	{
		if (!is_n((*av)[1]) || *ft_strwhile(*av + 2, &is_n))
			break ;
		option_n = true;
	}
	print(av, false);
	if (!option_n)
		ft_putchar('\n');
	return (0);
}
