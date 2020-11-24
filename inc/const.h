/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:03:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 17:50:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define MSH_ERR	"minishell: "
# define MSH_PS1	"\x1B[92m$USER\x1B[0m: \x1B[94m$SHELL\x1B[0m \\$ "
# define MSH_PS2	"> "

# define MSH_UNSUPPORTED_MULTILINE	"Unsupported multiline commands"

# define MSH_STOKEN	"'\"$"

# define MSH_PWDMAX_SIZE	8192

# define MSH_HISTORY_SIZE	64

#endif
