/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 20:47:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/19 14:36:23 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environment.h"
#include "parser.h"
#include "utils.h"

void			msh_parse_words(t_list *l, t_list *env)
{
	t_token	*t;
	char	*d;

	while (l)
	{
		if ((t = msh_token(l))->type == TOKEN_WORD)
		{
			if (!(d = msh_env_expand(env, t->value)))
				msh_abort("parser");
			free(t->value);
			t->value = d;
		}
		l = l->next;
	}
}
