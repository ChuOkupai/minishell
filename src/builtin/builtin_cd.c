/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:34:39 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/22 16:04:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtin.h"
#include "utils.h"

#define ERR_CD		"minishell: cd: %s: %s\n"
#define ERR_NOTSET	"minishell: cd: %s not set\n"

static int	usage(void)
{
	ft_putendl("cd: cd [DIR]");
	ft_putendl("    Change the shell working directory.");
	ft_putendl("    ");
	ft_putendl("    Change the current directory to DIR.");
	ft_putendl("    The default DIR is the value of the HOME shell variable.");
	ft_putendl("    ");
	ft_putendl("    Exit Status:");
	ft_putstr("    Returns 0 if the directory is changed");
	ft_putendl(", non-zero otherwise.");
	return (2);
}

static int	change_dir(t_env *env, const char *path, bool print)
{
	char *pwd;

	pwd = msh_getcwd();
	if (chdir(path) < 0)
	{
		ft_free(pwd);
		return (!!ft_dprintf(STDERR_FILENO, ERR_CD, path, msh_strerrno()));
	}
	if (print)
		ft_putendl(path);
	if (env_get(env, "OLDPWD") && pwd)
		env_set(env, "OLDPWD", pwd);
	ft_free(pwd);
	if (env_get(env, "PWD") && (pwd = msh_getcwd()))
	{
		env_set(env, "PWD", pwd);
		ft_free(pwd);
	}
	return (0);
}

static int	cd_from_var(t_env *env, const char *name, bool print)
{
	const char *path;

	if ((path = env_get(env, name)))
		return (change_dir(env, path, print));
	return (!!ft_dprintf(STDERR_FILENO, ERR_NOTSET, name));
}

int			builtin_cd(char **av, t_shell *s)
{
	if (!av[1])
		return (cd_from_var(&s->env, "HOME", false));
	if (!ft_strcmp(av[1], "--help"))
		return (usage());
	if (av[2])
		return (msh_perrorr(*av, ARG_TOOMANY, 1));
	if (!ft_strcmp(av[1], "-"))
		return (cd_from_var(&s->env, "OLDPWD", true));
	return (change_dir(&s->env, av[1], false));
}
