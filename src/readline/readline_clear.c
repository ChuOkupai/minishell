/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:58:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/06 20:01:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "readline.h"

void	readline_clear(t_readline *r)
{
	if (r->stream)
		ft_fclose(r->stream);
	ft_free(r->buf);
}
