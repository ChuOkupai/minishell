/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:08:34 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/12 18:43:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"

/*
** All known stack events.
** STACK_EMPTY:		if stack is empty
** STACK_NEMPTY:	if stack is not empty
** STACK_POP:		pop 1
** STACK_PUSH:		push 1
*/
enum	e_stack_event
{
	STACK_EMPTY = 1,
	STACK_NEMPTY,
	STACK_POP,
	STACK_PUSH
};
typedef enum e_stack_event	t_stack_event;

/*
** A transition rule in the finite state machine
** from:	The current state id
** to:		The next state id
** type:	The symbol associated with the transition
** event:	The stack event associated with the transition (0 for none)
*/
struct	s_rule
{
	int				from;
	int				to;
	t_token_type	type;
	t_stack_event	event;
};
typedef struct s_rule	t_rule;

# define STATE_SIZE	6
# if STATE_SIZE < 1
#  error "Illegal value set for variable STATE_SIZE"
# endif

/*
** The finite state machine used for minishell.
** final:	is final state?
** last:	temporary array for O(k) complexity where k is the number of rules
**			for the given state
** rule:	all transitions rules of the FSM
** size:	number of transitions rules
** stack:	used for parenthesis detection
*/
struct	s_fsm
{
	bool			final[STATE_SIZE];
	int				last[STATE_SIZE];
	const t_rule	*rule;
	size_t			size;
	int				stack;
};
typedef struct s_fsm	t_fsm;

/*
** Checks if the given list of tokens is a valid expression.
** If ouput_sequence, every states are displayed to STDERR_FILENO.
** Returns true if the expression is valid.
*/
bool	msh_is_valid(t_list *tokens, bool ouput_sequence);

#endif
