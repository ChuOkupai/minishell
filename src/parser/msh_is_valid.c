/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:26:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/13 17:19:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "const.h"
#include "parser.h"
#include "utils.h"

static bool	init(t_pda *a, const t_rule *rule, size_t size)
{
	size_t i;

	a->final[0] = true;
	a->final[1] = true;
	a->final[5] = true;
	a->rule = rule;
	i = 0;
	while (i < size)
	{
		a->last[rule[i].from] = i + 1;
		++i;
	}
	return (true);
}

static int	next(t_token *t, t_pda *a, int n, int state)
{
	while (n-- && a->rule[n].from == state)
		if (a->rule[n].type == t->type)
		{
			if (!a->rule[n].event)
				return (a->rule[n].to);
			else if ((a->rule[n].event == STACK_EMPTY && a->stack) ||
			(a->rule[n].event == STACK_NEMPTY && !a->stack))
				continue ;
			else if (a->rule[n].event == STACK_POP && --a->stack < 0)
				break ;
			else if (a->rule[n].event == STACK_PUSH)
				++a->stack;
			return (a->rule[n].to);
		}
	return (-1);
}

static bool	check(t_list *l, t_pda *a, bool output)
{
	t_list	*l2;
	int		s;

	s = 0;
	a->stack = 0;
	l2 = NULL;
	while (l && (s = next(l->content, a, a->last[s], s)) >= 0)
		if (output && !ft_list_push(&l2, ft_list_new((void *)((size_t)s))))
			msh_abort();
		else
			l = l->next;
	if (output)
	{
		l2 = ft_list_rev(l2);
		ft_list_print_fd(l2, (t_gprint_fd) & ft_putnbr_fd, STDERR_FILENO);
		ft_list_clear(&l2, NULL);
	}
	if (l)
		msh_perror_format(MSH_UNEXPECTED "`%s'", msh_token(l)->value);
	else if (a->stack)
		msh_perror_format(MSH_UNEXPECTED "`%c'", (a->stack < 0 ? ')' : '('));
	else if (!a->final[s])
		msh_perror(MSH_UNEXPECTED "`newline'");
	return (l ? false : a->final[s]);
}

bool		msh_is_valid(t_list *tokens, bool ouput_sequence)
{
	static bool			initialized = false;
	static t_pda		a;
	static const t_rule	rule[] = {
		{ 0, 0, TOKEN_LEFT_PAR, STACK_PUSH }, { 0, 1, TOKEN_WORD, 0 },
		{ 0, 2, TOKEN_REDIRECT, 0 },
		{ 1, 0, TOKEN_SEMICOLON, STACK_EMPTY }, { 1, 1, TOKEN_WORD, 0 },
		{ 1, 2, TOKEN_REDIRECT, 0 }, { 1, 3, TOKEN_PIPE, 0 },
		{ 1, 4, TOKEN_LOGICAL_OP, 0 }, { 1, 5, TOKEN_RIGHT_PAR, STACK_POP },
		{ 2, 1, TOKEN_WORD, 0 },
		{ 3, 1, TOKEN_WORD, 0 }, { 3, 2, TOKEN_REDIRECT, 0 },
		{ 4, 1, TOKEN_WORD, 0 }, { 4, 2, TOKEN_REDIRECT, 0 },
		{ 4, 5, TOKEN_LEFT_PAR, STACK_PUSH },
		{ 5, 0, TOKEN_SEMICOLON, STACK_EMPTY }, { 5, 4, TOKEN_LOGICAL_OP, 0 },
		{ 5, 5, TOKEN_RIGHT_PAR, STACK_POP }
	};

	if (!initialized)
		initialized = init(&a, rule, sizeof(rule) / sizeof(*rule));
	return (check(tokens, &a, ouput_sequence));
}
