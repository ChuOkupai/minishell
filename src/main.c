/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:22:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/04 16:01:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	int		ret;

	ft_bzero(&shell, sizeof(t_shell));
	if (msh_shell_init(&shell, ac, av, env) < 0)
		msh_abort("initialization");
	ret = msh_shell_run(&shell);
	msh_shell_clear(&shell);
	return (ret);
}
