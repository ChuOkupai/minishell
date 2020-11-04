/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:49:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/04 14:25:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

char	*msh_readline(t_readline *r, const t_history *h, const char *prompt)
{
	char *s;

	(void)h;
	if (prompt)
		ft_putstr(prompt);
	ft_getline(&s, r->stream);
	return (s);
}
