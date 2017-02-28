/*
 * ****************
** HEADER MBA
** ****************
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> //TODO del
#include "core.h"
#include "libft.h"

uint32_t			process_alive(t_env env)
{
	static int		id = 0;
	uint32_t		i;
	uint32_t		nbalive;

	i = 0;
	nbalive = 0;
	while (i < env.nbprocess)
	{
		if (env.process[i].isdead == FALSE)
		{
			dprintf(1, "\nIS NOT DEAD : %u \n", env.process[i].id); //TODO del
			id = env.process[i].id;
			nbalive++;
		}
		++i;
	}
	if (nbalive == 0)
	{
		dprintf(1, "Process alive : nbalive = 0 ; id = %u\n", id); //TODO del
		return (id);
	}
	dprintf(1, "%u processus en vie\n", nbalive); //TODO del
	return (0);
}

t_env		process_map(t_env env, t_env (*fct)(t_env env, int i))
{
	uint32_t		i;

	i = 0;
	while (i < env.nbprocess)
	{
		env = (*fct)(env, i);
		++i;
	}
	return (env);
}

t_process	get_process_by_id(t_env env, uint32_t id)
{
	uint32_t		i;

	i = 0;
	if (id == 0)
		return ((t_process){0});
	while (i < env.nbprocess)
	{
		if (env.process[i].id == id)
			return (env.process[i]);
		++i;
	}
	return ((t_process){0});
}

t_process	new_process(t_options opt, int id)
{
	t_process	process;
	
	process.id = random_uint32();
	process.pc = (MEM_SIZE / opt.nbchampions) * id;
	process.reg[0] = process.id;
	process.alive = 0;
	process.nb_cycle = 0;
	process.carry = 0;
	process.isdead = FALSE;
	return (process);
}

t_env		create_process(t_env env, t_options opt)
{
	uint32_t	i;

	i = 0;
	while (i < opt.nbchampions)
	{
		env.process[i] = new_process(opt, i);
		if ((env = load_champion(env, opt, i)).error == 1)
			return (env);
		++i;
	}
	check_random(env.process, opt.nbchampions);
	return (env);
}
