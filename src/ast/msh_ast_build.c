/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:34:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 14:21:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "parser.h"

/*
** Converts the next command from a list of tokens into a postfix expression.
** Returns a list of AST nodes.
*/
/*static t_list	*convert(t_list *l, t_list **end)
{
	t_list	*out;
	t_list	*stack;
	t_token	*t;

	out = NULL;
	stack = NULL;
	while (l && msh_token(l)->type != TOKEN_SEMICOLON)
		if (t->type == TOKEN_WORD || t->type == TOKEN_REDIRECT)
			ft_list_pushl(&out, ft_list_popl(&l));
		else if ((t = msh_token(l))->type == TOKEN_LOGICAL_OP)
		{
			while (stack && msh_token(stack)->type == TOKEN_LOGICAL_OP &&
			(void *)t < stack->content)
				ft_list_pushl(&out, ft_list_popl(&stack));
			ft_list_pushl(&stack, ft_list_popl(&l));
		}
		else if (t->type == TOKEN_RIGHT_PAR)
		{
			while (stack && msh_token(stack)->type != TOKEN_LEFT_PAR)
				ft_list_pushl(&out, ft_list_popl(&stack));
			ft_list_pop(&l, (t_gfunction) & msh_token_clear);
			ft_list_pop(&stack, (t_gfunction) & msh_token_clear);
		}
		else
			ft_list_pushl(&stack, ft_list_popl(&l));
	while (stack && msh_token(stack)->type != TOKEN_LEFT_PAR)
		ft_list_pushl(&out, ft_list_popl(&stack));
	*end = l;
	return (ft_list_rev(out));
}*/

t_list	*msh_ast_build(t_list *tokens)
{
	t_list	*commands;
	t_btree	*ast;

	commands = NULL;
	(void)ast;
	(void)tokens;
	return (commands);
}
