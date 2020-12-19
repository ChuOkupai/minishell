/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:00:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 15:27:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "utils.h"

#define RAND_PATH	"/dev/urandom"
#define WARN_UNKNOW	"shell-init: warning - unrecognized option `%s'\n"
#define WARN_SEED	"shell-init: warning - `%s' not found\n"

static void		seed_init(void)
{
	int		f;
	t_u64	seed;

	f = open(RAND_PATH, O_RDONLY);
	if (f < 0)
		seed = ft_rand() * ft_dprintf(STDERR_FILENO, WARN_SEED, RAND_PATH);
	else
	{
		(void)(read(f, &seed, sizeof(seed)) + 1);
		close(f);
	}
	ft_seed(seed);
}

static t_option	options_init(int n, char **av)
{
	t_option	opt;
	int			i;

	opt = 0;
	i = 0;
	while (++i < n)
		if (!ft_strcmp(av[i], "--dump-all"))
			opt |= OPT_DUMP_AST | OPT_DUMP_EXEC | OPT_DUMP_TOKENS;
		else if (!ft_strcmp(av[i], "--dump-ast"))
			opt |= OPT_DUMP_AST;
		else if (!ft_strcmp(av[i], "--dump-exec"))
			opt |= OPT_DUMP_EXEC;
		else if (!ft_strcmp(av[i], "--dump-tokens"))
			opt |= OPT_DUMP_TOKENS;
		else
			ft_dprintf(STDERR_FILENO, WARN_UNKNOW, av[i]);
	return (opt);
}

int				shell_init(t_shell *s, int ac, char **av, char **env)
{
	ft_bzero(s, sizeof(t_shell));
	ft_malloc_hook(&msh_exit);
	seed_init();
	env_init(&s->env, env);
	if (readline_init(&s->readline) < 0)
	{
		shell_clear(s);
		return (-1);
	}
	s->options = options_init(ac, av);
	return (0);
}
