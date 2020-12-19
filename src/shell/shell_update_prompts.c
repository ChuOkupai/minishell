/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_update_prompts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:04:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 16:40:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"
#include "shell.h"

static char	*exp_prompt(t_env *env, const char *s)
{
	t_exp exp;

	exp_init(&exp, env, EXP_BACKSLASH | EXP_QUOTE | EXP_DQUOTE | EXP_VAR);
	expand(&exp, s);
	return (exp.dst);
}

static char	*update(t_env *env, char *old, const char *ps, const char **old_ps)
{
	if (ps == *old_ps)
		return (old);
	*old_ps = ps;
	ft_free(old);
	return (exp_prompt(env, ps));
}

void		shell_update_prompts(t_shell *s)
{
	static const char	*old_ps1 = NULL;
	static const char	*old_ps2 = NULL;
	const char			*ps;

	ps = env_get(&s->env, "PS1");
	s->ps1 = update(&s->env, s->ps1, (ps ? ps : MSH_PS1), &old_ps1);
	ps = env_get(&s->env, "PS2");
	s->ps2 = update(&s->env, s->ps2, (ps ? ps : MSH_PS2), &old_ps2);
}
