/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:43:05 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 17:24:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"
#include "process.h"
#include "shell.h"

static t_list	*merge(t_list *l, t_list *args)
{
	t_list *l2;

	l->content = ft_list_pop(&args);
	if (!args)
		return (l);
	l2 = ft_list_last(args);
	l->next = ft_list_merge(args, l->next);
	return (l2);
}

static void		expand_args(t_list *l, const t_env *env)
{
	t_exp exp;

	if (!l || shell_interrupted())
		return ;
	exp_init(&exp, env, EXP_ALL);
	expand(&exp, l->content);
	ft_free(l->content);
	if (exp.args)
	{
		l = merge(l, exp.args);
		exp.args = NULL;
	}
	else
	{
		l->content = exp.dst;
		exp.dst = NULL;
	}
	exp_clear(&exp);
	expand_args(l->next, env);
}

static void		expand_redir(t_list *l, const t_env *env)
{
	if (!l || shell_interrupted())
		return ;
	redir_expand(l->content, env);
	expand_redir(l->next, env);
}

void			process_expand(t_process *p, const t_env *env)
{
	expand_args(p->args, env);
	ft_list_remove_if(&p->args, NULL, &ft_compare_pointer, NULL);
	p->argv = (char **)ft_list_to_array(p->args);
	expand_redir(p->redirection, env);
}
