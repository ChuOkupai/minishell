/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:35:12 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/24 17:49:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "shell.h"
#include "utils.h"

#define MSH_ERROR	"minishell: %s: %s: %s"

int	builtin_env(char **argv, t_shell *shell)
{
	if (argv[1])
		return (msh_perrorr(1, MSH_ERROR, *argv, argv[1], strerror(EINVAL)));
	ft_list_foreach(shell->env.list, (t_gfunction) & ft_putendl);
	return (0);
}
