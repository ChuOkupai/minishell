/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_command_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 18:30:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command.h"
#include "utils.h"

t_command	*msh_command_new(char **argv)
{
	t_command *cmd;

	if (!(cmd = malloc(sizeof(t_command))))
		msh_abort();
	cmd->argv = argv;
	return (cmd);
}
