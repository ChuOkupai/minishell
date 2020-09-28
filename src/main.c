/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:22:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 20:25:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"

int	main(int ac, char **av, char **env)
{
	t_shell	*shell;
	int		ret;

	if (!(shell = msh_shell_new(ac, av, env)))
		msh_abort("initialization");
	ret = msh_shell_run(shell);
	msh_shell_clear(shell);
	return (ret);
}
