/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:34:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:48:04 by asoursou         ###   ########.fr       */
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
	while (s && token(s)->type == TOKEN_LOGICAL_OP && (void*)t < s->content)
	{
		a = astnode_new(ast_type(token(s)->value), NULL);
		ft_list_push(out, ft_list_popl(&s))->content = a;
	}
	ft_list_push(&s, ft_list_popl(l));
	*stack = s;
}

static void		push_right_par(t_list **l, t_list **out, t_list **stack)
{
	t_list	*s;
	t_btree	*a;

	s = *stack;
	while (s && token(s)->type != TOKEN_LEFT_PAR)
	{
		a = astnode_new(ast_type(token(s)->value), NULL);
		ft_list_push(out, ft_list_popl(&s))->content = a;
	}
	token_clear(ft_list_pop(l));
	token_clear(ft_list_pop(&s));
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
	t_btree	*a;

	out = NULL;
	stack = NULL;
	while (*l && token(*l)->type != TOKEN_SEMICOLON)
		if ((t = token(*l))->type == TOKEN_LOGICAL_OP)
			push_priority_op(l, &out, &stack, t);
		else if (t->type == TOKEN_RIGHT_PAR)
			push_right_par(l, &out, &stack);
		else if (t->type == TOKEN_WORD || t->type == TOKEN_REDIRECT)
			ft_list_push(&out, ft_list_new(astnode_new(AST_PROCESS,
		ast_seq(l))));
		else
			ft_list_push(&stack, ft_list_popl(l));
	while (stack)
	{
		a = astnode_new(ast_type(token(stack)->value), NULL);
		ft_list_push(&out, ft_list_popl(&stack))->content = a;
	}
	return (ft_list_rev(out));
}

static t_list	*build_tree(t_list *l)
{
	t_list	*stack;
	t_ast	*a;
	t_btree	*right;
	t_btree	*left;

	stack = NULL;
	while (l)
	{
		if ((a = ast(l->content))->type != AST_PROCESS)
		{
			right = ft_list_pop(&stack);
			left = ft_list_pop(&stack);
			l->content = ft_btree_merge(l->content, left, right);
		}
		ft_list_push(&stack, ft_list_popl(&l));
	}
	return (stack);
}

t_list			*ast_build(t_list *tokens)
{
	t_list	*asts;

	asts = NULL;
	while (tokens)
		if (token(tokens)->type == TOKEN_SEMICOLON)
			token_clear(ft_list_pop(&tokens));
		else
			ft_list_push(&asts, build_tree(convert(&tokens)));
	return (ft_list_rev(asts));
}
