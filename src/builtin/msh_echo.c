/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:49:41 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/21 20:07:41 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	msh_option_n(char *arg)
{
	int		n;

	n = 1;
	while (n && arg[n])
	{
		if (arg[n] == 'n')
			n++;
		else
			n = 0;
	}
	return (n);
}

int			msh_echo(char **argv)
{
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (argv[i] && argv[i][0] == '-' && !(msh_option_n(argv[i])))
	{
		n = 1;
		i++;
	}
	while (argv[i])
	{
		ft_putstr(argv[i]);
		if (argv[++i])
			ft_putchar(' ');
	}
	if (!n)
		ft_putchar('\n');
	return (0);
}
