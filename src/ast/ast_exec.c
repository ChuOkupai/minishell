/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:45:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 15:01:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "job.h"

typedef int	(*t_evaluate)(t_btree *, t_shell *);

static int	eval_and(t_btree *r, t_shell *s)
{
	int ret;

	ret = ast_exec(r->left, s);
	if (ret)
		return (ret);
	return (ast_exec(r->right, s));
}

static int	eval_or(t_btree *r, t_shell *s)
{
	if (ast_exec(r->left, s))
		return (ast_exec(r->right, s));
	return (0);
}

static int	eval_job(t_btree *r, t_shell *s)
{
	return (env_setstatus(&s->env, job_exec(ast(r)->sequence, s)));
}

int			ast_exec(t_btree *r, t_shell *s)
{
	static const t_evaluate eval_func[AST_SIZE] = {
		&eval_and, &eval_or, &eval_job
	};

	if (s->discard)
		return (s->env.status.value);
	return (eval_func[ast(r)->type](r, s));
}
