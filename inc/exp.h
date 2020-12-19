/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:26:42 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 16:56:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_H
# define EXP_H
# include "env.h"
# include "wcexp.h"

/*
** exp_word flags
*/
enum		e_exp_flag
{
	EXP_BACKSLASH = 1,
	EXP_QUOTE = 1 << 1,
	EXP_DQUOTE = 1 << 2,
	EXP_VAR = 1 << 3,
	EXP_WILDCARD = 1 << 4,
	EXP_ALL = 0x1f
};
typedef enum e_exp_flag	t_exp_flag;

/*
** dst:			final string (without wildcard expansion)
** args:		list of matched wildcards arguments
** env:			the environment to use
** flags:		rules used for expansion
** wc:			wildcard parser structure
** wc_found:	true if a wildcard has been found
*/
struct		s_wexp
{
	char		*dst;
	t_list		*args;
	const t_env	*env;
	t_exp_flag	flags;
	t_wcexp		wc;
	bool		wc_found;
};
typedef struct s_wexp	t_exp;

typedef const char	*(*t_exp_func)(t_exp *, t_string *, const char *);

typedef struct s_exp_pair	t_exp_pair;
struct		s_exp_pair
{
	const char			c;
	const t_exp_func	function;
};

void		exp_init(t_exp *w, const t_env *env, t_exp_flag flags);
void		exp_clear(t_exp *w);

/*
** Expands a string using the given environment.
** The result of the expansion is stored in args.
*/
void		expand(t_exp *w, const char *s);

/*
** Expands a backslash.
*/
const char	*exp_backslash(t_exp *w, t_string *d, const char *s);

/*
** Expands a double quoted string.
*/
const char	*exp_dquote(t_exp *w, t_string *d, const char *s);

/*
** Expands a single quoted string.
*/
const char	*exp_quote(t_exp *w, t_string *d, const char *s);

/*
** Expands a variable.
*/
const char	*exp_var(t_exp *w, t_string *d, const char *s);

/*
** Expands a wildcard.
*/
const char	*exp_wildcard(t_exp *w, t_string *d, const char *s);

/*
** Expands a word.
*/
void		exp_word(t_exp *w, t_string *d, const char *s);

#endif
