/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:24:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 19:43:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"
#include "utils.h"

void		msh_process_clear(t_process *p)
{
	free(p->argv);
	free(p);
}

t_process	*msh_process_new(char **argv)
{
	t_process *p;

	if (!(p = malloc(sizeof(t_process))))
		msh_abort("process");
	p->argv = argv;
	return (p);
}
