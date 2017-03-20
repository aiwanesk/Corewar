/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:44:20 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 16:43:19 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"

t_env				process_map(t_env env, t_env (*fct)(t_env env, int i))
{
	int			i;

	i = (int)env.nbprocess;
	while (--i > -1)
		env = (*fct)(env, i);
	return (env);
}

t_env				add_cycle(t_env env, int i)
{
	if (env.process[i].pc < 0)
		env.process[i].pc += MEM_SIZE;
	env.process[i].nb_cycle++;
	return (env);
}

t_env				execute_cpu(t_env env, int i)
{
	if (env.process[i].isdead == FALSE)
		cpu(&env.process[i], &env);
	return (env);
}

t_env				process_live(t_env env, int i)
{
	if (env.process[i].alive == 0)
		env.process[i].isdead = TRUE;
	else
		env.process[i].alive = 0;
	return (env);
}

t_env				create_fork(t_env env, int i)
{
	if (env.process[i].fork.isfork == TRUE)
	{
		env.process[i].fork.isfork = FALSE;
		++env.nbprocess;
		if (env.nbprocess >= env.maxprocess)
		{
			env.maxprocess += PAGE_PROC;
			env.process = realloc(env.process, sizeof(t_process) *
					(env.maxprocess + 1));
		}
		ft_memcpy(&env.process[env.nbprocess - 1], &env.process[i],
														sizeof(t_process));
		if (env.process[i].fork.pc < 0)
			env.process[i].fork.pc += MEM_SIZE;
		env.process[env.nbprocess - 1].pc = env.process[i].fork.pc % MEM_SIZE;
		env.process[env.nbprocess - 1].id = ++env.idfork;
		env.process[env.nbprocess - 1].alive = 1;
	}
	return (env);
}
