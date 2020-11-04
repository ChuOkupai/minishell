/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:56:27 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/04 16:38:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "const.h"
#include "utils.h"

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

static int	export_args(char **argv, t_shell *shell)
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
			old_value = msh_env_get(&shell->env, argv[i]);
			value = ft_strjoin(old_value, value);
		}
		msh_env_set(&shell->env, argv[i], value);
		if (plus)
			ft_delete(value);
	}
	return (0);
}

static void	print_declare(const char *var)
{
	int i;

	i = ft_strchrnul(var, '=') - var;
	if (!var[i])
		return ;
	ft_printf("declare -x %.*s=\"", i, var);
	var += i;
	while (*(++var))
		*var == '"' ? ft_putstr("\\\"") : ft_putchar(*var);
	ft_putstr("\"\n");
}

int			msh_export(char **argv, t_shell *shell)
{
	if (argv[1])
		return (export_args(argv, shell));
	ft_list_foreach(shell->env.list, (t_gfunction) & print_declare);
	return (0);
}
