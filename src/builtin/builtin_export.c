/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:56:27 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/15 18:52:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtin.h"

static int	usage(void)
{
	ft_putendl("export: export [NAME[[=|+=]VALUE] ...]");
	ft_putendl("    Set export attribute for shell variables.");
	ft_putendl("    ");
	ft_putstr("    Marks each NAME for automatic export to the environment");
	ft_putendl(" of subsequently");
	ft_putendl("    executed commands.");
	ft_putendl("    If VALUE is supplied, assign VALUE before exporting.");
	ft_putstr("    If the operator += is used, it concatenates the VALUE");
	ft_putendl(" to the already existing one.");
	ft_putendl("    ");
	ft_putendl("    Exit Status:");
	ft_putendl("    Returns success unless NAME is invalid.");
	return (2);
}

static int	print_env(char **t)
{
	const char *s;
	const char *eq;

	while (*t)
	{
		s = *t++;
		eq = ft_strchr(s, '=');
		if (!eq)
		{
			ft_printf("declare -x %.*s\n", (int)(eq - s), s);
			continue ;
		}
		ft_printf("declare -x %.*s=\"", (int)(eq - s), s);
		s = eq;
		while (*(++s))
			if (ft_strchr("\\\"", *s))
				ft_printf("\\%c", *s);
			else
				ft_putchar(*s);
		ft_putstr("\"\n");
	}
	return (0);
}

static int	export(t_env *env, char *s)
{
	size_t	n;
	char	*op;
	bool	plus;

	n = ft_isdigit(*s) ? 0 : env_varlen(s);
	op = s + n;
	if (n && !*op)
	{
		env_set(env, s, NULL);
		return (0);
	}
	plus = *op == '+';
	op += plus;
	if (!n || *op != '=')
		return (-1);
	++op;
	plus ? env_appendn(env, s, op, n) : env_setn(env, s, op, n);
	return (0);
}

int			builtin_export(char **av, t_shell *s)
{
	int		r;
	size_t	i;

	if (!av[1])
		return (print_env(s->env.array));
	else if (!ft_strcmp(av[1], "--help"))
		return (usage());
	r = 0;
	i = 0;
	while (av[++i])
		if (export(&s->env, av[i]) < 0)
			r = ft_dprintf(STDERR_FILENO, INVALID_ID, *av, av[i]);
	return (!!r);
}
