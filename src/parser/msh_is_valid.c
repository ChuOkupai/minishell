/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:26:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/11 19:41:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const.h"
#include "parser.h"
#include "utils.h"

static bool	init(int *last, const t_rule *rule, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		last[rule[i].from] = i + 1;
		++i;
	}
	return (true);
}

static int	next(t_token *t, const t_rule *rule, int n, int state)
{
	while (n-- && rule[n].from == state)
		if (rule[n].type == t->type)
			return (rule[n].to);
	msh_perror_format(MSH_UNEXPECTED "`%s'", t->value);
	return (-1);
}

static bool	check(t_list *l, const bool *final, int *last, const t_rule *rule)
{
	int state;

	state = 0;
	while (l && (state = next(l->content, rule, last[state], state)) >= 0)
		l = l->next;
	if (!l && !final[state])
		msh_perror(MSH_UNEXPECTED "`newline'");
	return (l ? false : final[state]);
}

bool		msh_is_valid(t_list *tokens)
{
	static bool			initialized = false;
	static const bool	final[STATE_SIZE] = { true, true, false, false };
	static int			last[STATE_SIZE];
	static const t_rule	rule[] = {
		{ 0, TOKEN_WORD, 1 },
		{ 0, TOKEN_REDIRECTION, 1 },
		{ 1, TOKEN_SEMICOLON, 0 },
		{ 1, TOKEN_WORD, 1 },
		{ 1, TOKEN_REDIRECTION, 2 },
		{ 1, TOKEN_PIPE, 3 },
		{ 2, TOKEN_WORD, 1 },
		{ 3, TOKEN_WORD, 1 },
		{ 3, TOKEN_REDIRECTION, 2 }
	};

	if (!initialized)
		initialized = init(last, rule, sizeof(rule) / sizeof(*rule));
	return (check(tokens, final, last, rule));
}
