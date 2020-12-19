/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:34:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 19:07:18 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "parser.h"

/*
** Push operators with a higher precedence to the output list before adding the
** new one to the stack.
** Returns the stack.
*/

static t_list	*push_priority_op(t_list **l, t_list **out, t_list *stack)
{
	t_token *op;

	while (stack && (op = stack->content)->type == TOKEN_LOGICAL_OP)
		ft_list_push(out, ft_list_popl(&stack))->content =
		astnode_new(ast_type(op->value), NULL);
	ft_list_push(&stack, ft_list_popl(l));
	return (stack);
}

static t_list	*push_right_par(t_list **l, t_list **out, t_list *stack)
{
	t_token *op;

	while (stack && (op = stack->content)->type != TOKEN_PAR_LEFT)
		ft_list_push(out, ft_list_popl(&stack))->content =
		astnode_new(ast_type(op->value), NULL);
	token_clear(ft_list_pop(l));
	token_clear(ft_list_pop(&stack));
	return (stack);
}

/*
** Converts the next command from a list of tokens into a postfix expression.
** Returns a list of AST nodes.
*/

static t_list	*postfix(t_list **l)
{
	t_list	*out;
	t_list	*stack;
	t_token	*t;
	t_btree	*a;

	out = NULL;
	stack = NULL;
	while (*l && (t = (*l)->content)->type != TOKEN_SEMICOLON)
		if (t->type == TOKEN_LOGICAL_OP)
			stack = push_priority_op(l, &out, stack);
		else if (t->type == TOKEN_PAR_RIGHT)
			stack = push_right_par(l, &out, stack);
		else if (t->type == TOKEN_WORD || t->type == TOKEN_REDIRECT)
			ft_list_push(&out, ft_list_new(ast_build_seq(l)));
		else
			ft_list_push(&stack, ft_list_popl(l));
	while (stack)
	{
		a = astnode_new(ast_type(token(stack->content)->value), NULL);
		ft_list_push(&out, ft_list_popl(&stack))->content = a;
	}
	return (ft_list_rev(out));
}

static t_list	*build_tree(t_list *l)
{
	t_list	*stack;
	t_ast	*a;
	t_btree	*right;

	stack = NULL;
	while (l)
	{
		if ((a = ast(l->content))->type != AST_JOB)
		{
			right = ft_list_pop(&stack);
			l->content = ft_btree_merge(l->content, ft_list_pop(&stack), right);
		}
		ft_list_push(&stack, ft_list_popl(&l));
	}
	return (stack);
}

t_list			*ast_build(t_list *l)
{
	t_list *asts;

	asts = NULL;
	while (l)
	{
		if (token(l->content)->type == TOKEN_SEMICOLON)
			ft_list_pop(&l);
		ft_list_push(&asts, build_tree(postfix(&l)));
	}
	return (ft_list_rev(asts));
}
