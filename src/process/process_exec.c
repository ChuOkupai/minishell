/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:07:29 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/24 17:32:36 by asoursou         ###   ########.fr       */
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

static t_fct_ptr	get_builtin(const char *name)
{
	static char			*fct_name[] = { "cd", "echo", "env", "exit", "export",
						"pwd", "unset" };
	static t_fct_ptr	fct_ptr[] = { &builtin_cd, &builtin_echo, &builtin_env,
						&builtin_exit, &builtin_export, &builtin_pwd,
						&builtin_unset };
	size_t				i;

	i = sizeof(fct_name) / sizeof(*fct_name);
	while (i--)
		if (!ft_strcmp(name, fct_name[i]))
			return (fct_ptr[i]);
	return (NULL);
}

int					process_exec(t_list *process, t_shell *shell)
{
	t_process	*p_content;
	int			input;
	int			output;
	t_fct_ptr	builtin_func;

	p_content = process->content;
	input = dup(STDIN_FILENO);
	output = dup(STDOUT_FILENO);
	if (!p_content->argv[0])
	{
		redirect(p_content);
		undirect(input, output);
		return (env_setstatus(&shell->env, 0));
	}
	if (!process->next && (builtin_func = get_builtin(p_content->argv[0])))
	{
		if (redirect(p_content))
			return (env_setstatus(&shell->env, 1));
		env_setstatus(&shell->env, builtin_func(p_content->argv, shell));
		undirect(input, output);
		return (shell->env.status);
	}
	return (env_setstatus(&shell->env, process_run(shell, process)));
}
