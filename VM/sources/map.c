/*
 * ****************
** HEADER MBA
** ****************
*/

#include "core.h"
#include "libft.h"

t_env		process_map(t_env env, t_env (*fct)(t_env env, int i))
{
	int			i;

	i = (int)env.nbprocess;
	while (--i > -1)
		env = (*fct)(env, i);
	return (env);
}

t_env			add_cycle(t_env env, int i)
{
	env.process[i].nb_cycle++;
	return (env);
}

t_env			execute_cpu(t_env env, int i)
{
	if (env.process[i].isdead == FALSE)
		cpu(&env.process[i], &env);
	return (env);
}

t_env			create_fork(t_env env, int i)
{
	if (env.process[i].fork.isfork == TRUE)
	{
		env.process[i].fork.isfork = FALSE;
		++env.nbprocess;
		if (env.nbprocess >= env.maxprocess)
		{
			env.maxprocess += PAGE_PROC;
			env.process = realloc(env.process, sizeof(t_process) * (env.maxprocess + 1));
		}
		ft_memcpy(&env.process[env.nbprocess - 1], &env.process[i],
														sizeof(t_process));
		env.process[env.nbprocess - 1].pc = env.process[i].fork.pc;
	}
	return (env);
}
