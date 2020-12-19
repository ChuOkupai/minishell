/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 04:36:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 05:00:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init(t_pda *p, const t_rule *rules, size_t n)
{
	size_t i;

	p->final[0] = true;
	p->final[1] = true;
	p->final[5] = true;
	p->rules = rules;
	i = 0;
	while (i < n)
	{
		p->last[rules[i].from] = i + 1;
		++i;
	}
}

void		pda_init(t_pda *p)
{
	static const t_rule	rules[] = {
		{ 0, 0, TOKEN_PAR_LEFT, STACK_PUSH }, { 0, 1, TOKEN_WORD, 0 },
		{ 0, 2, TOKEN_REDIRECT, 0 },
		{ 1, 0, TOKEN_SEMICOLON, STACK_EMPTY }, { 1, 1, TOKEN_WORD, 0 },
		{ 1, 2, TOKEN_REDIRECT, 0 }, { 1, 3, TOKEN_PIPE, 0 },
		{ 1, 4, TOKEN_LOGICAL_OP, 0 }, { 1, 5, TOKEN_PAR_RIGHT, STACK_POP },
		{ 2, 1, TOKEN_WORD, 0 },
		{ 3, 1, TOKEN_WORD, 0 }, { 3, 2, TOKEN_REDIRECT, 0 },
		{ 4, 1, TOKEN_WORD, 0 }, { 4, 2, TOKEN_REDIRECT, 0 },
		{ 4, 4, TOKEN_PAR_LEFT, STACK_PUSH },
		{ 5, 0, TOKEN_SEMICOLON, STACK_EMPTY }, { 5, 4, TOKEN_LOGICAL_OP, 0 },
		{ 5, 5, TOKEN_PAR_RIGHT, STACK_POP }
	};

	ft_bzero(p, sizeof(*p));
	init(p, rules, sizeof(rules) / sizeof(*rules));
}
