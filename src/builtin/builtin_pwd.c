/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:43:09 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/15 14:43:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtin.h"
#include "utils.h"

#define ERR_CWD	"minishell: pwd: error retrieving current directory: %s: %s\n"
#define ARG_0	"getcwd: cannot access parent directories"

static int	usage(void)
{
	ft_putendl("pwd: pwd");
	ft_putendl("    Print the name of the current working directory.");
	ft_putendl("    ");
	ft_putendl("    Exit Status:");
	ft_putendl("    Returns 0 unless the current directory cannot be read.");
	return (2);
}

int			builtin_pwd(char **av, t_shell *s)
{
	char *pwd;

	(void)s;
	if (av[1] && !ft_strcmp(av[1], "--help"))
		return (usage());
	pwd = msh_getcwd();
	if (!pwd)
		return (!!ft_dprintf(STDERR_FILENO, ERR_CWD, ARG_0, msh_strerrno()));
	ft_putendl(pwd);
	ft_free(pwd);
	return (0);
}
