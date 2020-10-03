/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:27:48 by gdinet            #+#    #+#             */
/*   Updated: 2020/10/03 11:00:53 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"
#include "libft.h"

int		msh_unset(char **argv, t_shell *shell)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (argv[i])
	{
		if (!msh_check_name(argv[i]))
		{
			msh_perror("%s: %s: not a valid identifier", argv[0], argv[i]);
			ret = 1;
		}
		msh_env_unset(&shell->env, argv[i]);
		i++;
	}
	return (ret);
}
