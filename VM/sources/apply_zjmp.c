/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:18:38 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 18:38:22 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
**zjmp : Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage des
** paramètres derrière cette opération dont l’opcode est de 9.
*/

static void		dbg(t_process *proc, int32_t val1, int32_t isok)
{
	ft_putstr("P\t");
	ft_putstr("\033[1;");
	ft_putnbr((31 + (proc->idlive % 7)));
	ft_putstr(";40m");
	ft_putnbr(proc->id);
	ft_putstr(" | zjmp ");
	ft_putnbr(val1);
	if (isok == 1)
		ft_putstr(" OK");
	else
		ft_putstr(" KO");
	ft_putendl("");
	ft_putstr(C_NONE);
}

void					apply_zjmp(t_process *process, t_env *env)
{
	int16_t			addr;

	addr = get_args(env->memory, (process->pc + BYPASS_ARG) % MEM_SIZE, T_DIR);
	if (process->carry == 1)
		process->pc = (process->pc + (addr % IDX_MOD)) % MEM_SIZE;
	else
		process->pc = (process->pc + 3) % MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
	process->nb_cycle -= 20;
	if (env->dbg)
		dbg(process, addr, process->carry);
}
