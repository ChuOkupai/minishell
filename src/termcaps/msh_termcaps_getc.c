/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_termcaps_getc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:23:17 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/26 19:37:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const.h"
#include "termcaps.h"

int		msh_termcaps_getc(t_file *f)
{
	int c;
	int d;

	if ((c = ft_fgetc(f)) == FT_EOF || c != '\x1b')
		return (c);
	c = ft_fgetc(f);
	if (c == FT_EOF || c != '[' || (d = ft_fgetc(f)) == FT_EOF)
		return ('\x1b');
	if (d == 'A')
		return (MSH_KEY_UP);
	else if (d == 'B')
		return (MSH_KEY_DOWN);
	else if (d == 'C')
		return (MSH_KEY_RIGHT);
	else if (d == 'D')
		return (MSH_KEY_LEFT);
	return ('\x1b');
}
