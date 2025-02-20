/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:14:31 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/12 16:01:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include <stdbool.h>

/*
** All known symbols type.
** TOKEN_WILDCARD is only used during word expansion.
*/
enum		e_token_type
{
	TOKEN_WORD,
	TOKEN_MULTILINE,
	TOKEN_REDIRECT,
	TOKEN_PIPE,
	TOKEN_SEMICOLON,
	TOKEN_LOGICAL_OP,
	TOKEN_PAR_LEFT,
	TOKEN_PAR_RIGHT,
	TOKEN_WILDCARD
};
typedef enum e_token_type	t_token_type;

/*
** Represents a token.
** type:	type of the token
** value:	graphical representation
*/
struct		s_token
{
	t_token_type	type;
	char			*value;
};
typedef struct s_token	t_token;

t_token		*token_new(t_token_type type, char *value);
void		token_clear(t_token *t);

/*
** Tries to find a token from the lexer in the given string s.
** Returns the address of the static token if found in the lexer.
** Returns NULL if the token is not recognized.
*/
t_token		*token_find(const char *s);

/*
** Returns true if the token is a TOKEN_WORD or a TOKEN_MULTILINE.
*/
bool		token_is_dynamic(const t_token *t);

/*
** Destroy a token if it is dynamic, without destroying its content.
** Returns the value stored in the token.
*/
char		*token_pop(t_token *t);

/*
** Prints a token to the standard ouput.
*/
void		token_print(const t_token *t);

/*
** Returns a token structure, from a generic pointer type.
*/
t_token		*token(void *content);

#endif
