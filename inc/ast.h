/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:05:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 14:22:56 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H
# include "libft.h"
# include "process.h"

/*
** All possible node types in the abstract syntax tree (AST).
*/
enum	e_ast_type
{
	AST_AND,
	AST_OR,
	AST_PROCESS
};
typedef enum e_ast_type	t_ast_type;

/*
** Represents a node in the AST.
** type:		type of AST node
** sequence:	contains a sequence of process if type == AST_PROCESS
*/
struct	s_ast
{
	t_ast_type	type;
	t_list		*sequence;
};
typedef struct s_ast	t_ast;

/*
** Get the AST node stored in a list of ASTs.
** Returns NULL if the element does not exist.
*/
t_btree	*msh_ast_node(t_list *element);

/*
** Get the AST stored in a t_btree node.
** Returns NULL if the element does not exist.
*/
t_ast	*msh_ast(t_btree *element);

/*
** Creates a new sequence of process from the given list of tokens.
** Utility function used in msh_ast_build.
** Returns a list of process.
*/
t_list	*msh_ast_build_sequence(t_list **tokens);

/*
** Build a list of ASTs from a list of valid tokens.
** Returns the list of ASTs.
*/
t_list	*msh_ast_build(t_list *tokens);

/*
** Free an AST node.
*/
void	msh_ast_clear(t_ast *node);

/*
** Creates a new AST node.
*/
t_ast	*msh_ast_new(t_ast_type type);

/*
** Prints an AST node to the standard ouput.
*/
void	msh_ast_print(t_ast *node);

#endif
