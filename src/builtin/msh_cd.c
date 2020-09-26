/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:34:39 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/26 16:14:12 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "builtin.h"
#include "libft.h"
#include "const.h"
#include "environment.h"

int		msh_cd_home(void)
{
	return (0);
}

int		msh_cd(char **argv, t_shell *shell)
{
	if ((!argv[1] && msh_cd_home()) || chdir(argv[1]) == -1)
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
