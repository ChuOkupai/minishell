/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_terminate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:41:48 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/07 17:42:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process_terminate(t_process *p, int status)
{
	p->terminated = true;
	p->status = status;
}
