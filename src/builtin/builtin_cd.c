/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:34:39 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/24 17:02:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "shell.h"
#include "utils.h"

static int	cd_home(t_env *env)
{
	const char *path;

	if ((path = env_get(env, "HOME")))
		return (!chdir(path));
	return (msh_perrorr(1, MSH_ERR "cd: HOME not set"));
}

static void	update_pwd(t_pwd *pwd)
{
	if (!pwd->size)
	{
		pwd->size = 128;
		if (!(pwd->pwd = ft_new(sizeof(char) * pwd->size)))
			msh_abort("environment");
	}
	if (!getcwd(pwd->pwd, pwd->size))
	{
		if (errno == ERANGE && pwd->size < MSH_PWDMAX_SIZE)
		{
			pwd->size *= 2;
			if (!(pwd->pwd = ft_realloc(pwd->pwd, 0, pwd->size, false)))
				msh_abort("environment");
			update_pwd(pwd);
		}
		else
			msh_abort("environment");
	}
}

int			builtin_cd(char **argv, t_shell *s)
{
	if (!argv[1])
		return (cd_home(&s->env));
	else if (chdir(argv[1]) == -1)
		return (msh_perrorr(1, MSH_ERR "%s: %s\n", argv[0], strerror(errno)));
	ft_delete(s->pwd.oldpwd);
	s->pwd.oldpwd = s->pwd.pwd ? ft_strdup(s->pwd.pwd) : NULL;
	update_pwd(&s->pwd);
	if (env_get(&s->env, "PWD"))
		env_set(&s->env, "PWD", s->pwd.pwd);
	if (env_get(&s->env, "OLDPWD"))
		env_set(&s->env, "OLDPWD", s->pwd.oldpwd);
	return (0);
}
