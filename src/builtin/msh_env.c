/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:35:12 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/28 17:08:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"
#include "libft.h"

int				msh_env(char **argv, t_shell *shell)
{
	t_list	*l_env;

	if (argv[1])
		return (msh_perrorr(1, "%s: %s: invalid argument", argv[0], argv[1]));
	l_env = shell->env->list;
	while (l_env)
	{
		ft_putendl(l_env->content);
		l_env = l_env->next;
	}
	return (0);
}
