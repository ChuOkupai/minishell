/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:56:27 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/24 17:48:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"

#define MSH_INVALID_ID	"minishell: %s: %s: not a valid identifier"

static bool	find_equal(char *arg, char **value)
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

static int	export_args(char **av, t_shell *shell)
{
	int			i;
	char		*value;
	const char	*old_value;
	bool		plus;

	i = 0;
	value = NULL;
	while (av[++i])
	{
		plus = find_equal(av[i], &value);
		if (!check_name(av[i]))
			return (msh_perrorr(1, MSH_INVALID_ID, *av, av[i]));
		if (plus)
		{
			old_value = env_get(&shell->env, av[i]);
			value = ft_strjoin(old_value, value);
		}
		env_set(&shell->env, av[i], value);
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

int			builtin_export(char **argv, t_shell *shell)
{
	if (argv[1])
		return (export_args(argv, shell));
	ft_list_foreach(shell->env.list, (t_gfunction) & print_declare);
	return (0);
}
