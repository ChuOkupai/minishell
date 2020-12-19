/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:36:41 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/09 19:58:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redir.h"

t_redir	*redir_new(t_redir_op op, char *raw_path)
{
	t_redir *r;

	r = ft_malloc(sizeof(t_redir));
	r->op = op;
	r->raw_path = raw_path;
	r->path = NULL;
	return (r);
}
