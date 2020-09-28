/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:07:29 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/28 17:06:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "utils.h"
#include "shell.h"
#include "builtin.h"

typedef int	(*t_fct_ptr)(char **, t_shell *);

static int	is_builtin(char *name)
{
	unsigned long		i;
	static char			*fct_name[] = {"cd", "echo", "env", "exit", "export",
	"pwd", "unset"};

	i = 0;
	while (i < sizeof(fct_name) / sizeof(char *))
	{
		if (!ft_strcmp(name, fct_name[i]))
			return (i);
		i++;
	}
	return (-1);
}

int			msh_process_exec(t_list *process, t_shell *shell)
{
	int					builtin;
	t_process			*p_content;
	static t_fct_ptr	fct[] = {&msh_cd, &msh_echo, &msh_env, &msh_exit,
	&msh_export, &msh_pwd, &msh_unset};

	p_content = process->content;
	if (!process->next && (builtin = is_builtin(p_content->argv[0])) != -1)
	{
		msh_redirect(p_content);
		return (fct[builtin](p_content->argv, shell));
	}
	else
		return (msh_pipe(process, &shell->env));
}
