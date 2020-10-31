/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:49:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/15 14:39:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

char	*msh_readline(t_readline *r, const t_history *h, const char *prompt)
{
	char *s;

	(void)h;
	if (prompt)
		ft_putstr(prompt);
	if (ft_getline(&s, r->stream) == FT_EOF)
	{
		if (ft_feof(r->stream))
			ft_putstr("  \b\b");
		else
			s = ft_delete(s);
	}
	return (s);
}
