/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:58:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 21:50:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "readline.h"

void	msh_readline_clear(t_readline *r)
{
	if (r->init)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &r->old_termios);
	ft_list_clear(&r->history.list, &free);
	if (r->stream)
		ft_fclose(r->stream);
	ft_memdel(r->buf);
}
