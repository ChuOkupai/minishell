/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:08:34 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/11 19:42:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"

# define STATE_SIZE	4
# if STATE_SIZE < 1
#  error "Illegal value set for variable STATE_SIZE"
# endif

/*
** A transition rule in the finite state machine
** from:	The current state id
** type:	The symbol associated with the transition
** to:		The next state id
*/
struct	s_rule
{
	int				from;
	t_token_type	type;
	int				to;
};
typedef struct s_rule	t_rule;

/*
** Checks if the given list of tokens is a valid expression.
*/
bool	msh_is_valid(t_list *tokens);

#endif
