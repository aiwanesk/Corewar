/*
 * ****************
** HEADER MBA
** ****************
*/

#include "core.h"
#include "libft.h"

t_env			add_cycle(t_env env, int i)
{
	env.process[i].nb_cycle++;
	return (env);
}

t_env			process_live(t_env env, int i)
{
	if (env.process[i].alive == 0)
		env.process[i].isdead = TRUE;
	else
		env.process[i].isdead = FALSE;
	env.process[i].alive = 0;
	return (env);
}

t_env			execute_cpu(t_env env, int i)
{
	if (env.process[i].isdead == FALSE)
		env.process[i] = cpu(env.process[i]);
	return (env);
}

t_env			create_fork(t_env env, int i)
{
	if (env.process[i].fork.isfork == TRUE)
	{
		env.process[i].fork.isfork = FALSE;
		ft_memcpy(&env.process[env.nbprocess++], &env.process[i],
														sizeof(t_process));
		env.process[env.nbprocess].pc = env.process[i].fork.pc;
	}
	return (env);
}
