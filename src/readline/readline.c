/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:49:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 20:22:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "readline.h"

char	*readline(t_readline *r, const char *prompt)
{
	char *s;

	if (r->buf)
	{
		s = r->buf;
		r->buf = NULL;
		return (s);
	}
	if (prompt)
		ft_putstr_fd(prompt, STDERR_FILENO);
	ft_getline(&s, r->stream);
	return (s);
}
