/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:48:41 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 17:12:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"
#include "redir.h"

void	redir_expand(t_redir *r, const t_env *env)
{
	t_exp exp;

	exp_init(&exp, env, EXP_BACKSLASH | EXP_QUOTE | EXP_DQUOTE);
	if (r->op != REDIR_HEREDOC_INPUT)
		exp.flags |= EXP_VAR | EXP_WILDCARD;
	expand(&exp, r->raw_path);
	if (exp.args)
		r->path = exp.args->next ? NULL : ft_list_pop(&exp.args);
	else
	{
		r->path = exp.dst;
		exp.dst = NULL;
	}
	exp_clear(&exp);
}
