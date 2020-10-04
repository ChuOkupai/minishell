/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/04 14:17:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "shell.h"

int	msh_shell_run(t_shell *s)
{
	t_list	*ast;
	t_btree	*b;

	s->line_no = 1;
	s->keep = true;
	while (s->keep)
	{
		ast = msh_shell_read_command(s);
		if (s->options.dump_ast)
			ft_list_print(ast, (t_gprint) & msh_astnode_print);
		while (ast)
		{
			b = ft_list_pop(&ast, NULL);
			msh_ast_exec(b, s);
			ft_btree_clear(&b, (t_gfunction) & msh_ast_clear);
		}
		++s->line_no;
	}
	return (s->env.status);
}
