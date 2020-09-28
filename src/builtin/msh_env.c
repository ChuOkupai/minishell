/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:35:12 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/28 17:04:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"
#include "libft.h"

int		msh_env(char **argv, t_shell *shell)
{
	if (argv[1])
		return (msh_perrorr(1, "%s: %s: invalid argument", argv[0], argv[1]));
	ft_list_print(shell->env.list, (t_gprint) & ft_putendl);
	return (0);
}