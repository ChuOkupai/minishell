/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:08:34 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 17:49:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"

/*
** All known symbols type.
*/
enum	e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIRECT,
	TOKEN_PIPE,
	TOKEN_SEMICOLON,
	TOKEN_LOGICAL_OP,
	TOKEN_LEFT_PAR,
	TOKEN_RIGHT_PAR,
	TOKEN_MULTILINE,
	TOKEN_SIZE
};
typedef enum e_token_type	t_token_type;

/*
** Represents a token.
** type:	type of the token
** value:	graphical representation
** size:	size of value (avoid calls to ft_strlen)
*/
struct	s_token
{
	t_token_type	type;
	char			*value;
	size_t			size;
};
typedef struct s_token	t_token;

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
** A transition rule in the pushdown automaton
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
** The pushdown automaton used for minishell.
** final:	is final state?
** last:	temporary array for O(k) complexity where k is the number of rules
**			for the given state
** rule:	all transitions rules of the FSM
** stack:	used for parenthesis detection
*/
struct	s_pda
{
	bool			final[STATE_SIZE];
	int				last[STATE_SIZE];
	const t_rule	*rule;
	int				stack;
};
typedef struct s_pda	t_pda;

/*
** Checks if the given list of tokens is a valid expression.
** If ouput_sequence, every states are displayed to STDERR_FILENO.
** Returns 1 if the expression is valid, 0 if invalid, -1 if multiline.
*/
int		msh_is_valid(t_list *tokens, bool ouput_sequence);

/*
** Expands all tokens of type TOKEN_WORD into arguments.
** The list of tokens MUST be valid before calling this function.
*/
void	msh_parse_words(t_list *tokens, t_list *env);

/*
** Get the token stored in a list of tokens.
** Returns NULL if the element does not exist.
*/
t_token	*msh_token(t_list *element);

/*
** Free a token of type TOKEN_WORD or TOKEN_MULTILINE.
** If the token is already from the g_lexer, nothing happens.
*/
void	msh_token_clear(t_token *token);

/*
** Prints a token to the standard ouput.
*/
void	msh_token_print(t_token *token);

/*
** Creates a list of tokens from a string.
** Allocates memory only for tokens of type TOKEN_WORD or TOKEN_MULTILINE.
** Returns the new list of tokens.
*/
t_list	*msh_tokenize(const char *string);

#endif
