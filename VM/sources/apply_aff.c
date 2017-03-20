/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:04:19 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 17:44:21 by mbarbari         ###   ########.fr       */
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
	ft_putstr(" | aff ");
	ft_putnbr(val1);
	ft_putendl("");
	ft_putstr(C_NONE);
}

void			apply_aff(t_process *process, t_env *env)
{
	t_args		args[3];
	int32_t	pc;
	int32_t	reg;
	char		val;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	pc = process->pc + BYPASS_ARG_ENCODE;
	reg = get_args(env->memory, pc, args[0].length);
	if (reg > 0 && reg <= REG_NUMBER)
	{
		val = (process->reg[reg - 1] & 0xFF);
		write(1, &val, 1);
	}
	process->nb_cycle -= 2;
	process->pc += BYPASS_ARG_ENCODE + args[0].length;
	process->pc = process->pc % MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
	if (env->dbg)
		dbg(process, reg);
}
