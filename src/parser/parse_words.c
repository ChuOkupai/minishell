/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 20:47:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 15:21:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "utils.h"

void		parse_words(t_list *l, t_env *env)
{
	t_token	*t;
	char	*d;

	while (l)
	{
		if ((t = token(l))->type == TOKEN_WORD)
		{
			if (!(d = env_expand(env, t->value)))
				msh_abort("parser");
			free(t->value);
			t->value = d;
		}
		l = l->next;
	}
}
