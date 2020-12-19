/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:27:48 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/15 18:58:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtin.h"

static int	usage(void)
{
	ft_putendl("unset: unset [NAME ...]");
	ft_putendl("    Unset values and attributes of shell variables.");
	ft_putendl("    ");
	ft_putendl("    For each NAME, remove the corresponding variable.");
	return (2);
}

int			builtin_unset(char **av, t_shell *s)
{
	int		r;
	size_t	i;
	size_t	j;

	if (av[1] && !ft_strcmp(av[1], "--help"))
		return (usage());
	r = 0;
	i = 0;
	while (av[++i])
		if ((j = env_varlen(av[i])) && !av[i][j])
			env_unset(&s->env, av[i]);
		else
			r |= !!ft_dprintf(STDERR_FILENO, INVALID_ID, *av, av[i]);
	return (r);
}
