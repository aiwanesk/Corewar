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
	env.ui = opt.ui;
	env.dump = opt.dumpcycle;
	env.nbprocess = opt.nbchampions;
	i = 0;
	env = create_process(env, opt);
	while (i < opt.nbchampions)
	{
		env.process[i].alive = 1;
		//Useless noew
//		env.process[i].memory = env.memory;
		++i;
	}
	env.run = TRUE;
	env.cycle_to_die = CYCLE_TO_DIE;
	return (env);
}

int			winner(t_env env, t_process process)
{
	if (process.id == 0)
		ft_putendl(C_MAGENTA"Match NULL");
	else
	{
		protocol_win(env, process);
		ft_putstr(C_MAGENTA"Le joueur ");
		ft_putnbr_uint32(process.id);
		ft_putstr("(");
		ft_putstr(process.name);
		ft_putendl(") a gagne");
	}
	return (FALSE);
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

void				core(t_env env)
{
	while (1)
	{
		++env.cycles;
		if (env.dump > 0 && env.cycles >= env.dump)
		{
			print_memory(env.memory);
			return ;
		}
		else if (env.cycles >= env.cycle_to_die)
		{
			env = process_map(env, &process_live);
			env.cycles = env.cycles % env.cycle_to_die;
		}
		//print_memory(env.memory);
		//printf("\n\n");
		//printf("nb total Cycle :%u\n", env.cycles);
		//printf("pc->p1[%u]=memory[%d]\n", env.process[0].pc, env.process[0].memory[env.process[0].pc]);
	//	printf("pc->p2[%u]=memory[%d]\n", env.process[1].pc, env.process[1].memory[env.process[1].pc]);
		//dprintf(1, "TEST1 ; Lecture du cycle : %u\n", env.cycles);
		protocol_lc(env);
		if (process_alive(env) <= 1)
		{
			winner(env, get_last_player(env));
			return ;
		}
		env = process_map(env, &add_cycle);
		env = process_map(env, &execute_cpu);
		env = process_map(env, &create_fork);
		protocol_sleep(env);
	}
}
