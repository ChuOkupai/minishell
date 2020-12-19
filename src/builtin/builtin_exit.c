/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:59:50 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/15 15:25:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "builtin.h"
#include "utils.h"

#define ERR_NUMERIC	"minishell: exit: %s: numeric argument required\n"

static int	usage(void)
{
	ft_putendl("exit: exit [N]");
	ft_putendl("    Exit the shell.");
	ft_putendl("    ");
	ft_putendl("    Exits the shell with a status of N.");
	ft_putstr("    If N is omitted");
	ft_putendl(", the exit status is that of the last command executed.");
	return (2);
}

static int	ret_success(t_shell *s, const char *arg, t_u8 value)
{
	if (arg)
		ft_dprintf(STDERR_FILENO, ERR_NUMERIC, arg);
	s->keep = false;
	return (value);
}

int			builtin_exit(char **av, t_shell *s)
{
	bool	negative;
	t_u8	value;

	if (!av[1])
		return (ret_success(s, NULL, s->env.status.value));
	if (!ft_strcmp(av[1], "--help"))
		return (usage());
	negative = av[1][0] == '-';
	if (*ft_strwhile(av[1] + negative, ft_isdigit))
		return (ret_success(s, av[1], 2));
	if (av[2])
		return (msh_perrorr(*av, ARG_TOOMANY, 1));
	errno = 0;
	value = ft_atoi(av[1]);
	if (errno)
		return (ret_success(s, av[1], 2));
	return (ret_success(s, NULL, value));
}
