/*
 * ****************
** HEADER MBA
** ****************
*/

#include "virtual_machine.h"
#include "libft.h"


t_env	init_virtual_machine(t_options opt)
{
	t_env		env;

	ft_bzero(&env, sizeof(t_env));
	if (opt.dumpcycle > 0)
		env.isdump = TRUE;
	env.nb_process = opt.nbchampions;
	return (env);
}

int				winner(int		id)
{
	//TODO : need to change
	return (id);
}

int				virtual_machine(t_env env)
{
	uint32_t		id;
	int				process;

	if ((id = process_alive(env)) < 1)
		return (winner(id));
	process = 0;
	while (process < env.nb_process)
	{
		env.process[process].nb_cycle++;
		env.process[process].memory = env.memory;
		//cpu(env.process[process]);
	}
	return (virtual_machine(env));
}
