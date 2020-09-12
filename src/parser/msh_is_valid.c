/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:26:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/12 19:10:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "const.h"
#include "parser.h"
#include "utils.h"

static bool	init(t_fsm *m, const t_rule *rule, size_t size)
{
	size_t i;

	m->final[0] = true;
	m->final[1] = true;
	m->final[5] = true;
	m->rule = rule;
	i = 0;
	while (i < size)
	{
		m->last[rule[i].from] = i + 1;
		++i;
	}
	return (true);
}

static int	next(t_token *t, t_fsm *m, int n, int state)
{
	while (n-- && m->rule[n].from == state)
		if (m->rule[n].type == t->type)
		{
			if (!m->rule[n].event)
				return (m->rule[n].to);
			else if ((m->rule[n].event == STACK_EMPTY && m->stack) ||
			(m->rule[n].event == STACK_NEMPTY && !m->stack))
				continue ;
			else if (m->rule[n].event == STACK_POP && --m->stack < 0)
				break ;
			else if (m->rule[n].event == STACK_PUSH)
				++m->stack;
			return (m->rule[n].to);
		}
	return (-1);
}

static bool	check(t_list *l, t_fsm *m, bool output)
{
	t_list	*l2;
	int		s;

	s = 0;
	m->stack = 0;
	l2 = NULL;
	while (l && (s = next(l->content, m, m->last[s], s)) >= 0)
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
	else if (m->stack)
		msh_perror_format(MSH_UNEXPECTED "`%c'", (m->stack < 0 ? ')' : '('));
	else if (!m->final[s])
		msh_perror(MSH_UNEXPECTED "`newline'");
	return (l ? false : m->final[s]);
}

bool		msh_is_valid(t_list *tokens, bool ouput_sequence)
{
	static bool			initialized = false;
	static t_fsm		m = { 0 };
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
		initialized = init(&m, rule, sizeof(rule) / sizeof(*rule));
	return (check(tokens, &m, ouput_sequence));
}
