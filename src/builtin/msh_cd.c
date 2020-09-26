/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:34:39 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/26 17:40:23 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "builtin.h"
#include "libft.h"
#include "const.h"
#include "utils.h"

static int	msh_cd_home(t_env *env)
{
	const char *path;

	if ((path = msh_env_get(env, "HOME")))
		return (chdir(path) == -1);
	return (msh_perrorr(1, MSH ": cd: HOME not set"));
}

int			msh_cd(char **argv, t_shell *shell)
{
	if (!argv[1] && msh_cd_home(shell->env))
		return (1);
	else if (chdir(argv[1]) == -1)
	{
		ft_dprintf(STDERR_FILENO, MSH ": %s: %s\n", argv[0], strerror(errno));
		return (1);
	}
	shell->env->old_pwd = shell->env->pwd;
	msh_update_pwd(shell->env);
	if (msh_env_get(shell->env, "PWD"))
		msh_env_set(shell->env, "PWD", shell->env->pwd);
	if (msh_env_get(shell->env, "OLDPWD"))
		msh_env_set(shell->env, "OLDPWD", shell->env->old_pwd);
	return (0);
}
