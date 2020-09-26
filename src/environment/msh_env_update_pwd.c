/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_update_pwd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:23:04 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/26 15:53:03 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "utils.h"
#include "const.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int		msh_update_pwd(t_env *env)
{
	if (!env->pwd_size)
	{
		env->pwd_size = 128;
		if (!(env->pwd = malloc(sizeof(char) * env->pwd_size)))
			msh_abort("environment");
	}
	if (!getcwd(env->pwd, env->pwd_size))
	{
		if (errno == ERANGE && env->pwd_size < MSH_PWDMAX_SIZE)
		{
			env->pwd_size *= 2;
			if (!(env->pwd = ft_realloc(env->pwd, 0, env->pwd_size, false)))
				msh_abort("environment");
			msh_update_pwd(env);
		}
		else
			msh_abort("environment");
	}
	return (0);
}
