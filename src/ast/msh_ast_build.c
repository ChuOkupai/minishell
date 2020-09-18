/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:34:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 17:42:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "parser.h"

/*
** Push operators with a higher precedence to the output list before adding the
** new one to the stack.
*/

static void		push_priority_op(t_list **l, t_list **out, t_list **stack,
				t_token *t)
{
	t_list	*s;
	t_btree	*a;

	s = *stack;
	while (s && msh_token(s)->type == TOKEN_LOGICAL_OP && (void*)t < s->content)
	{
		a = msh_ast_new(msh_ast_type(msh_token(s)->value), NULL);
		free(ft_list_pushl(out, ft_list_popl(&s))->content);
		(*out)->content = a;
	}
	ft_list_pushl(&s, ft_list_popl(l));
	*stack = s;
}

static void		push_right_par(t_list **l, t_list **out, t_list **stack)
{
	t_list	*s;
	t_btree	*a;

	s = *stack;
	while (s && msh_token(s)->type != TOKEN_LEFT_PAR)
	{
		a = msh_ast_new(msh_ast_type(msh_token(s)->value), NULL);
		free(ft_list_pushl(out, ft_list_popl(&s))->content);
		(*out)->content = a;
	}
	ft_list_pop(l, (t_gfunction) & msh_token_clear);
	ft_list_pop(&s, (t_gfunction) & msh_token_clear);
	*stack = s;
}

/*
** Converts the next command from a list of tokens into a postfix expression.
** Returns a list of AST nodes.
*/

static t_list	*convert(t_list **l)
{
	t_list	*out;
	t_list	*stack;
	t_token	*t;

	out = NULL;
	stack = NULL;
	while (*l && msh_token(*l)->type != TOKEN_SEMICOLON)
		if ((t = msh_token(*l))->type == TOKEN_LOGICAL_OP)
			push_priority_op(l, &out, &stack, t);
		else if (t->type == TOKEN_RIGHT_PAR)
			push_right_par(l, &out, &stack);
		else if (t->type == TOKEN_WORD || t->type == TOKEN_REDIRECT)
			ft_list_push(&out, msh_ast_new(AST_PROCESS, msh_ast_build_seq(l)));
		else
			ft_list_pushl(&stack, ft_list_popl(l));
	while (stack && msh_token(stack)->type != TOKEN_LEFT_PAR)
		ft_list_pushl(&out, ft_list_popl(&stack));
	return (ft_list_rev(out));
}

static t_list	*build_tree(t_list *l)
{
	return (l);
}

t_list			*msh_ast_build(t_list *tokens)
{
	t_list	*asts;

	asts = NULL;
	while (tokens)
		if (msh_token(tokens)->type == TOKEN_SEMICOLON)
			ft_list_pop(&tokens, (t_gfunction) & msh_token_clear);
		else
			asts = ft_list_merge(asts, build_tree(convert(&tokens)));
	asts = ft_list_rev(asts);
	while (asts)
	{
		ft_putendl("AST:");
		msh_astnode_print(asts->content, 0);
		ft_btree_clear((t_btree **)(&asts->content),
		(t_gfunction) & msh_ast_clear);
		ft_list_pop(&asts, NULL);
	}
	return (asts);
}
