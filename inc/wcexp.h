/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:52:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 17:05:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCEXP_H
# define WCEXP_H
# include "libft.h"

/*
** dot:	has a "./" been inserted?
** i:	start index of unparsed string
** l:	list of tokens
*/
struct	s_wcexp
{
	bool	dot;
	size_t	i;
	t_list	*l;
};
typedef struct s_wcexp	t_wcexp;

/*
** pattern:		current pattern to match
** prefix:		prefix of subexpression
** keep_hidden:	true if hidden files must be considered
** keep_dir:	true if output must only contains directories
*/
struct	s_expr
{
	t_list	*pattern;
	char	*prefix;
	bool	keep_hidden;
	bool	keep_dir;
};
typedef struct s_expr	t_expr;

void	wcexp_init(t_wcexp *w);
void	wcexp_clear(t_wcexp *w);

/*
** Push a new token into the list if the string contains new characters.
*/
t_list	*wcexp_expand(t_wcexp *w);

/*
** Push a new token into the list if the string contains new characters.
*/
void	wcexp_flush(t_wcexp *w, t_string *d);

/*
** Returns true if s match the wildcard expression.
*/
bool	wcexp_match(const char *s, const t_list *expr);

/*
** Split the list of tokens, and returns the next expression to match.
*/
void	wcexp_next(t_wcexp *w, t_expr *e);

/*
** Push a TOKEN_WILDCARD int the list of tokens.
*/
void	wcexp_push_sep(t_wcexp *w);

/*
** List all files in current path.
** Keep only t_entry matching the pattern (list of tokens)
** If hidden is set to true, list hidden files too.
** Returns a list of t_entry.
*/
t_list	*wcexp_readdir(const char *path, bool hidden);

/*
** Update the output list with the next subexpression.
*/
t_list	*wcexp_expand_expr(t_wcexp *w, t_list *ent);

#endif
