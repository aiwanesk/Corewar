/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:09:42 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 17:52:04 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

static void		dbg(t_process *proc, int32_t val1)
{
	ft_putstr("P\t");
	ft_putstr("\033[1;");
	ft_putnbr((31 + (proc->idlive % 7)));
	ft_putstr(";40m");
	ft_putnbr(proc->id);
	ft_putstr(" | live ");
	ft_putnbr(val1);
	ft_putendl("");
	ft_putstr(C_NONE);
}

void				apply_live(t_process *process, t_env *env)
{
	int32_t		tmp;
	int32_t		total;
	int32_t		length;

	tmp = 0;
	length = length_label(env->memory[process->pc]);
	total = (int32_t)get_args(env->memory, process->pc + 1, 4);
	process->alive++;
	while (tmp < MAX_PLAYERS)
	{
		if (env->idlive[tmp] == total)
			env->live[tmp]++;
		++tmp;
	}
	process->pc += (4 + 1);
	process->pc %= MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
	process->nb_cycle -= 10;
	protocol_lc(*env);
	if (env->dbg)
		dbg(process, total);
}
