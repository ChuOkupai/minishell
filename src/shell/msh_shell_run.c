/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 14:22:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ast.h"
#include "const.h"
#include "parser.h"
#include "shell.h"
#include "utils.h"

static bool	read_cmd(t_shell *s, const char *str)
{
	t_list	*l;
	int		r;

	if (!(l = msh_tokenize(str)))
		return (true);
	if (!(r = msh_is_valid(l)) || r < 0)
	{
		if (r < 0)
			msh_perror("warning: Unsupported multiline commands");
		return (!ft_list_clear(&l, (t_gfunction) & msh_token_clear));
	}
	msh_parse_words(l, s->env);
	if (s->opt.dump_tokens)
		ft_list_print(l, (t_gprint) & msh_token_print);
	//l = msh_ast_build(l);
	str = msh_token(l)->type == TOKEN_WORD && !ft_list_at(l, 1) ?
	msh_token(l)->value : "";
	if (!ft_strcmp(str, "exit"))
		return (ft_list_clear(&l, (t_gfunction) & msh_token_clear));
	if (!ft_strcmp(str, "env"))
		ft_list_foreach(s->env, (t_gfunction) & ft_putendl);
	return (!ft_list_clear(&l, (t_gfunction) & msh_token_clear));
}

int			msh_shell_run(t_shell *s)
{
	char *line;

	s->keep = true;
	while (s->keep)
	{
		msh_termcaps_update(s->term);
		ft_putstr(MSH_PS1);
		ft_getline(&line, s->stdin);
		if (ft_ferror(s->stdin))
			msh_abort("readline");
		else if (ft_feof(s->stdin))
		{
			ft_memdel(line);
			if (!(line = ft_strdup("exit")))
				msh_abort("readline");
			ft_putendl(line);
		}
		s->keep = read_cmd(s, line);
		ft_memdel(line);
	}
	return (0);
}
