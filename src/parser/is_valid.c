/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:26:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:41:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"

static int	next(t_token *t, t_pda *p, int n, int state)
{
	while (n-- && p->rules[n].from == state)
		if (p->rules[n].type == t->type)
		{
			if (!p->rules[n].event)
				return (p->rules[n].to);
			else if ((p->rules[n].event == STACK_EMPTY && p->stack) ||
			(p->rules[n].event == STACK_NEMPTY && !p->stack))
				continue ;
			else if (p->rules[n].event == STACK_POP && --p->stack < 0)
				break ;
			else if (p->rules[n].event == STACK_PUSH)
				++p->stack;
			return (p->rules[n].to);
		}
	return (-1);
}

static int	check(t_list *l, t_pda *p)
{
	int s;

	s = 0;
	p->stack = 0;
	while (l && (s = next(l->content, p, p->last[s], s)) >= 0)
		l = l->next;
	if (l)
		ft_dprintf(STDERR_FILENO, ERR_UNEXPECT, token(l->content)->value);
	else if (!p->final[s])
	{
		if (s == 3 || s == 4)
			return (-1);
		ft_dprintf(STDERR_FILENO, ERR_UNEXPECT, "newline");
	}
	else if (p->stack)
	{
		if (p->stack > 0)
			return (-1);
		ft_dprintf(STDERR_FILENO, ERR_UNEXPECT, ")");
	}
	return (l || !p->final[s] ? 0 : p->final[s]);
}

int			is_valid(t_list *tokens)
{
	static bool		init = false;
	static t_pda	p;
	t_list			*last;

	if (!init)
	{
		pda_init(&p);
		init = true;
	}
	last = ft_list_last(tokens);
	if (last && token(last->content)->type == TOKEN_MULTILINE)
		return (-1);
	return (check(tokens, &p));
}
