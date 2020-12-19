/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:35:12 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/16 13:20:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"

static int	usage(void)
{
	ft_putendl("env: env");
	ft_putstr("    Displays all the variables with their associated value");
	ft_putendl(" in the environment.");
	return (2);
}

static void	print(char **t)
{
	const char *eq;

	if (!*t)
		return ;
	eq = ft_strchr(*t, '=');
	if (eq)
		ft_putendl(*t);
	print(t + 1);
}

int			builtin_env(char **av, t_shell *s)
{
	if (av[1])
	{
		if (!ft_strcmp(av[1], "--help"))
			return (usage());
		return (msh_perrorr(*av, ARG_TOOMANY, 1));
	}
	print(s->env.array);
	return (0);
}
