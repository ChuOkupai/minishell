/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:22:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:33:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	int		ret;

	ft_bzero(&shell, sizeof(t_shell));
	if (shell_init(&shell, ac, av, env) < 0)
		msh_abort("initialization");
	ret = shell_run(&shell);
	shell_clear(&shell);
	return (ret);
}
