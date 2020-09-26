/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:03:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/26 14:03:44 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define MSH		"minishell"
# define MSH_PS1	"\x1B[92m$USER\x1B[0m: \x1B[94m$SHELL\x1B[0m \\$ "
# define MSH_PS2	"> "

# define MSH_STOKEN	"'\"$~*"

# define MSH_UNEXPECTED	"syntax error near unexpected token "

# define MSH_TERMBUFFER_SIZE	2048

# define MSH_INVALID_OPTION	"%s: %s: invalid option"

#endif
