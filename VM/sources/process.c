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
	uint32_t		i;
	uint32_t		nbalive;

	i = 0;
	nbalive = 0;
	while (i < env.nbprocess)
	{
		if (env.process[i].isdead == FALSE)
			nbalive++;
		++i;
	}
	return (nbalive);
}

t_process	get_process_by_id(t_env env, uint32_t id)
{
	uint32_t		i;

	i = 0;
	//TODO wut?
	if (id == 0)
		return (MATCH_NULL);
	while (i < env.nbprocess)
	{
		if (env.process[i].id == id)
			return (env.process[i]);
		++i;
	}
	return (MATCH_NULL);
}

t_process	new_process(t_options opt, int id)
{
	t_process	process;
	
	process.id = opt.id[id];
	process.pc = (MEM_SIZE / opt.nbchampions) * id;
	ft_bzero(process.reg, sizeof(uint32_t) * 16);
	process.reg[0] = convert_endianness(process.id);
	process.alive = 0;
	process.nb_cycle = 0;
	process.carry = 0;
	process.isdead = FALSE;
	return (process);
}

t_env		create_process(t_env env, t_options opt)
{
	t_process	proc;
	uint32_t	i;

	i = 0;
	while (i < opt.nbchampions)
	{
		proc = new_process(opt, i);
		ft_memcpy(&env.process[i], &proc, sizeof(t_process));
		if ((env = load_champion(env, opt, i)).error == 1)
			return (env);
		++i;
	}
	check_random(env.process, opt.nbchampions);
	return (env);
}
