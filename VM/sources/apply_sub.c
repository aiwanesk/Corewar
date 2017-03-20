/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:16:56 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 17:49:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** add : Opcode 4. Prend trois registres, additionne les 2 premiers, et met le r
** dans le troisième, juste avant de modifier le carry.
*/

static void		dbg(t_process *proc, int32_t val1, int32_t val2, int32_t val3)
{
	ft_putstr("P\t");
	ft_putstr("\033[1;");
	ft_putnbr((31 + (proc->idlive % 7)));
	ft_putstr(";40m");
	ft_putnbr(proc->id);
	ft_putstr(" | sub ");
	ft_putnbr(val1);
	ft_putstr(" ");
	ft_putnbr(val2);
	ft_putstr(" ");
	ft_putnbr(val3);
	ft_putendl("");
	ft_putstr(C_NONE);
}

void		apply_sub(t_process *process, t_env *env)
{
	int32_t		reg[3];
	int32_t		val;

	val = 0;
	reg[0] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE, T_REG);
	reg[1] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE + 1, T_REG);
	reg[2] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE + 2, T_REG);
	if (reg[0] > 0 && reg[0] <= REG_NUMBER &&
			reg[1] > 0 && reg[1] <= REG_NUMBER)
		val = process->reg[reg[0] - 1] - process->reg[reg[1] - 1];
	if (reg[2] > 0 && reg[2] <= REG_NUMBER)
		process->reg[reg[2] - 1] = val;
	process->carry = (val == 0);
	process->pc += BYPASS_ARG_ENCODE + 3;
	process->pc = process->pc % MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
	process->nb_cycle -= 10;
	if (env->dbg)
		dbg(process, reg[0], reg[1], reg[2]);
}
