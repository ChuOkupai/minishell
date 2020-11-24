/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:58:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 17:56:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "readline.h"

void	readline_clear(t_readline *r)
{
	return ;
	if (r->init)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &r->old_termios);
}
