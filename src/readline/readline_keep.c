/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_keep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:13:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/06 20:14:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_keep(t_readline *r, char *buf)
{
	r->buf = buf;
}