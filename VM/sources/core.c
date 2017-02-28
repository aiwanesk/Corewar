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
	dprintf(1, "On execute des truc sur le process : %u\n", process.id);
	return (process);
}

void				core(t_env env, uint32_t cycles)
{
	uint32_t		id;

	if (env.dump > 0 && cycles >= env.dump)
	{
		print_memory(env.memory);
		env.run = FALSE;
	}
	if (env.cycle_to_die <= 0)
		env.run = winner(MATCH_NULL);
	else if (cycles >= env.cycle_to_die)
	{
		env = process_map(env, &process_live);
		cycles = cycles % env.cycle_to_die;
	}
	if ((id = process_alive(env)) > 0)
		env.run = winner(get_process_by_id(env, id));
	env = process_map(env, &add_cycle);
	env = process_map(env, &execute_cpu);
	env = process_map(env, &create_fork);
	if (env.run)
		core(env, ++cycles);
}
