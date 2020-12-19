/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:23:21 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 17:23:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "shell.h"

void	job_expand(t_list *j, t_env *env)
{
	if (!j || shell_interrupted())
		return ;
	process_expand(j->content, env);
	job_expand(j->next, env);
}
