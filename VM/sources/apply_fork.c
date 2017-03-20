/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:05:51 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 17:43:38 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c.
** Crée un nouveau processus, qui hérite des différents états de son père,
** à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

static void		dbg(t_process *proc, int32_t val1)
{
	ft_putstr("P\t");
	ft_putstr("\033[1;");
	ft_putnbr((31 + (proc->idlive % 7)));
	ft_putstr(";40m");
	ft_putnbr(proc->id);
	ft_putstr(" | fork ");
	ft_putnbr(val1);
	ft_putendl("");
	ft_putstr(C_NONE);
}

void						apply_fork(t_process *process, t_env *env)
{
	int32_t			val;

	val = (int16_t)get_args(env->memory, process->pc + 1, T_DIR);
	process->fork.pc = (process->pc + (val % IDX_MOD)) % MEM_SIZE;
	process->fork.isfork = TRUE;
	process->nb_cycle -= 800;
	process->pc += BYPASS_ARG + T_DIR;
	process->pc = process->pc % MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
	if (env->dbg)
		dbg(process, val);
}
