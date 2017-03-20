/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:51:05 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 15:16:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"

static void			norme(t_env *env, t_options *opt)
{
	env->run = TRUE;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->dump = opt->dumpcycle;
	env->idfork = opt->id[0] + env->nbprocess - 1;
}

t_env				init_core(t_options opt)
{
	t_env		env;
	int32_t	i;
	t_process	*temp;

	ft_bzero(&env, sizeof(t_env));
	env.ui = opt.ui;
	env.dbg = opt.dbg;
	env.nbprocess = opt.nbchampions;
	env.maxprocess = PAGE_PROC;
	temp = (t_process *)malloc(sizeof(t_process) * (env.maxprocess + 1));
	i = 0;
	env.process = temp;
	if ((env = create_process(env, opt)).error == 1)
	{
		free(temp);
		return (env);
	}
	while (i < opt.nbchampions)
	{
		env.idlive[i] = env.process[i].id;
		env.live[i++] = 1;
	}
	while (i < MAX_PLAYERS)
		env.idlive[i++] = -1;
	norme(&env, &opt);
	return (env);
}

int					winner(t_env env, t_process process)
{
	protocol_win(env, process);
	ft_putstr(C_MAGENTA"Le joueur ");
	ft_putnbr_uint32(process.id);
	ft_putstr("(");
	ft_putstr(process.name);
	ft_putendl(") a gagne"C_NONE);
	return (FALSE);
}

t_env				check_live(t_env env)
{
	int		tmp;

	tmp = 0;
	while (tmp < MAX_PLAYERS)
	{
		if (env.idlive[tmp] >= 0 && env.live[tmp] <= 0)
			env.idlive[tmp] = -1;
		else if (env.idlive[tmp] >= 0)
			env.nblive += env.live[tmp];
		env.live[tmp++] = 0;
	}
	if (env.nblive >= NBR_LIVE)
	{
		env.cycle_to_die -= CYCLE_DELTA;
		env.nblive = 0;
	}
	else if (env.check >= MAX_CHECKS)
	{
		--env.cycle_to_die;
		env.check = 0;
	}
	else
		++env.check;
	env.cycles = 0;
	return (env);
}

void				core(t_env env)
{
	int				id;

	while (1)
	{
		if (env.dump != -1 && env.dump-- == 0)
		{
			print_memory(env.memory, env);
			break ;
		}
		else if (env.cycles++ >= env.cycle_to_die)
		{
			env = process_map(check_live(env), &process_live);
			env.cycles = 0;
		}
		if (!env.dbg && (id = process_alive(env)) >= 0)
		{
			winner(env, get_process_by_id(env, id));
			break ;
		}
		env = process_map(env, &add_cycle);
		env = process_map(env, &execute_cpu);
		env = process_map(env, &create_fork);
		protocol_sleep(env);
	}
	free(env.process);
}
