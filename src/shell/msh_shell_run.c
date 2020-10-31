/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/15 13:52:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "parser.h"
#include "shell.h"

int	msh_shell_run(t_shell *s)
{
	t_list	*l;
	t_btree	*b;

	s->line_no = 1;
	s->keep = true;
	while (s->keep)
	{
		l = msh_shell_read_command(s);
		if (s->options.dump_tokens && l)
			ft_list_print(l, (t_gprint) & msh_token_print);
		if ((l = msh_ast_build(l)))
			++s->line_no;
		if (s->options.dump_ast && l)
			ft_list_print(l, (t_gprint) & msh_astnode_print);
		while (l)
		{
			b = ft_list_pop(&l);
			msh_ast_exec(b, s);
			ft_btree_clear(&b, (t_gfunction) & msh_ast_clear);
		}
	}
	return (s->env.status);
}
