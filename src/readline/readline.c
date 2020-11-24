/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:49:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 18:55:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

char	*readline(t_readline *r, const t_history *h, const char *prompt)
{
	char	*s;
	int		ret;

	(void)h;
	if (prompt)
		ft_putstr(prompt);
	ret = ft_get_next_line(r->fd, &s);
	r->eof = ret < 1;
	return (s);
}
