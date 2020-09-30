/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:49:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 17:13:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

char	*msh_readline(t_readline *r, const t_history *h, const char *prompt)
{
	char *s;

	(void)h;
	if (prompt)
		ft_putstr(prompt);
	if (ft_getline(&s, r->stream) == FT_EOF && ft_ferror(r->stream))
		s = ft_memdel(s);
	return (s);
}
