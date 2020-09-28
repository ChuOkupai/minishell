/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:56:27 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/28 17:07:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "const.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

static bool	msh_find_equal(char *arg, char **value)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
		{
			arg[i] = '\0';
			*value = arg + i + 1;
			return (false);
		}
		if (arg[i] == '+' && arg[i + 1] == '=')
		{
			arg[i] = '\0';
			*value = arg + i + 2;
			return (true);
		}
		i++;
	}
	return (false);
}

int			msh_export(char **argv, t_shell *shell)
{
	int			i;
	char		*value;
	const char	*old_value;
	bool		plus;

	i = 0;
	value = NULL;
	while (argv[++i])
	{
		plus = msh_find_equal(argv[i], &value);
		if (!msh_check_name(argv[i]))
		{
			return (msh_perrorr(1, "%s: %s: not a valid identifier",
			argv[0], argv[i]));
		}
		if (plus)
		{
			old_value = msh_env_get(shell->env, argv[i]);
			value = ft_strjoin(old_value, value);
		}
		msh_env_set(shell->env, argv[i], value);
		if (plus)
			ft_memdel(value);
	}
	return (0);
}
