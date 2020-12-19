/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:52:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/07 20:15:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "readline.h"

int	readline_init(t_readline *r)
{
	if (!(r->stream = ft_fdopen(STDIN_FILENO, "r")))
		return (-1);
	return (0);
}
