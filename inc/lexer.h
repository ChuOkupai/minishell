/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:20:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/12 16:02:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
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
** Get the token stored in a list of tokens.
** Returns NULL if the element does not exist.
*/
t_token	*msh_token(t_list *element);

/*
** Free a token of type TOKEN_WORD.
** If the token is already from the g_lexer, nothing happens.
*/
void	msh_token_clear(t_token *token);

/*
** Tries to find a token from the lexer in the given string s.
** Returns the address of the static token if found in the lexer.
** Returns NULL if the token is of type TOKEN_WORD.
*/
t_token	*msh_token_find(const char *s);

/*
** Allocates memory for a new dynamic token of type TOKEN_WORD.
** Abort on error or with an NULL value.
*/
t_token	*msh_token_new(char *value, size_t size);

/*
** Prints a token to the standard ouput.
*/
void	msh_token_print(t_token *token);

/*
** Creates a list of tokens from a string.
** If a syntax error is encountered an error is displayed and NULL is returned.
** A syntax error could be an unclosed quoted string because multiline commands
** are not supported.
*/
t_list	*msh_tokenize(const char *string);

#endif
