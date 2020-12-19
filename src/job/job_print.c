/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:54:22 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 20:01:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void	job_print(const t_list *j)
{
	if (!j)
		return ;
	process_print(j->content);
	if (j->next)
		ft_putstr(" | ");
	job_print(j->next);
}
