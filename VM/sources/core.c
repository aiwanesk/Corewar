/*
 * ****************
** HEADER MBA
** ****************
*/

#include "core.h"
#include "libft.h"
#include <stdio.h> // TODO : TO DEL

t_env		init_core(t_options opt)
{
	t_env		env;
	uint32_t	i;

	ft_bzero(&env, sizeof(t_env));
	env.dump = opt.dumpcycle;
	env.nbprocess = opt.nbchampions;
	i = 0;
	env = create_process(env, opt);
	while (i < opt.nbchampions)
	{
		env.process[i].alive = 1;
		env.process[i].memory = env.memory;
		++i;
	}
	env.run = TRUE;
	env.cycle_to_die = CYCLE_TO_DIE;
	return (env);
}

int			winner(t_process process)
{
	if (process.id == 0)
		ft_putendl(C_MAGENTA"Match NULL");
	else
	{
		ft_putstr(C_MAGENTA"Le joueur ");
		ft_putnbr_uint32(process.id);
		ft_putstr("(");
		ft_putstr(process.name);
		ft_putendl(") a gagne");
	}
	return (FALSE);
}

//TODO : DEL FUNCTION
t_process		cpu(t_process process)
{
	static int		test = 0;

	if (test == 0)
	{
		process.fork.isfork = TRUE;
		process.pc = 10;
		++test;
	}
	dprintf(1, "Champion %s execute une fonction cpu\n", process.name);
	dprintf(1, "On execute des truc sur le process : %u\n", process.id);
	return (process);
}

t_process		get_last_player(t_env env)
{
	uint32_t	i;

	i = 0;
	while (i < env.nbprocess)
	{
		if (env.process[i].isdead == FALSE)
			return (env.process[i]);
		++i;
	}
	return (MATCH_NULL);
}

void				core(t_env env, uint32_t cycles)
{
	if (env.dump > 0 && cycles >= env.dump)
	{
		print_memory(env.memory);
		return ;
	}
	else if (cycles >= env.cycle_to_die)
	{
		env = process_map(env, &process_live);
		cycles = cycles % env.cycle_to_die;
	}
	if (process_alive(env) <= 1)
	{
		winner(get_last_player(env));
		return ;
	}
	if (env.cycle_to_die <= 0)
		winner(MATCH_NULL);
	env = process_map(env, &add_cycle);
	env = process_map(env, &execute_cpu);
	env = process_map(env, &create_fork);
	core(env, ++cycles);
}
