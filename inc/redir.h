/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:53:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:44:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H
# include "env.h"

# define ARG_AMBIGUOUS	"ambiguous redirect"

/*
** All possible redirections.
*/
enum		e_redir_op
{
	REDIR_INPUT,
	REDIR_HEREDOC_INPUT,
	REDIR_OUTPUT,
	REDIR_APPENDING_OUTPUT,
	REDIR_SIZE
};
typedef enum e_redir_op	t_redir_op;

/*
** op:			redirection operator
** raw_path:	path before expansion
** path:		path to the redirected file
*/
struct		s_redir
{
	t_redir_op	op;
	char		*raw_path;
	char		*path;
};
typedef struct s_redir	t_redir;

t_redir		*redir_new(t_redir_op op, char *raw_path);
void		redir_clear(t_redir *r);

/*
** Executes a redirection.
** Returns -1 on error, elso 0.
*/
int			redir_exec(const t_redir *r);

/*
** Expand the path of the redirection.
*/
void		redir_expand(t_redir *r, const t_env *env);

/*
** Returns true if the redirection is ambiguous.
*/
bool		redir_is_ambiguous(const t_redir *r);

/*
** Gets the redirection operator from a string.
** Returns -1 if unknown.
*/
t_redir_op	redir_op(const char *value);

/*
** Print a redirection.
*/
void		redir_print(const t_redir *r);

#endif
