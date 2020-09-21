/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:56:27 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/21 20:10:02 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"
#include "const.h"
#include "environment.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

static int	msh_check_name(char *name)
{
	int i;

	if (!name[0] || (!ft_isalpha(name[0]) && name[0] != '_'))
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
	}
	return (1);
}

static bool	msh_find_equal(char *arg, char *value)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
		{
			arg[i] = '\0';
			value = arg + i + 1;
			return (false);
		}
		if (arg[i] == '+' && arg[i + 1] == '=')
		{
			arg[i] = '\0';
			value = arg + i + 2;
			return (true);
		}
		i++;
	}
	return (false);
}

int			msh_export(char **argv, t_env *env)
{
	int			i;
	char		*value;
	const char	*old_value;
	bool		plus;

	i = 0;
	while (argv[i])
	{
		plus = msh_find_equal(argv[i], value);
		if (!msh_check_name(argv[i]))
		{
			return (msh_perrorr(1, "%s: %s: not a valid identifier\n",
			argv[0], argv[i]));
		}
		if (plus)
		{
			old_value = msh_env_get(env, argv[i]);
			value = ft_strjoin(old_value, value);
			free(value);
		}
		msh_env_set(env, argv[i], value);
		if (plus)
			ft_memdel(value);
	}
	return (0);
}
