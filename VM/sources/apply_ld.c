/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:06:24 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 18:35:35 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** Charge la valeur du premier paramètre dans le registre.
** T_DIR | T_IND, T_REG
*/

static void		dbg(t_process *proc, int32_t val1, int32_t val2)
{
	ft_putstr("P\t");
	ft_putstr("\033[1;");
	ft_putnbr((31 + (proc->idlive % 7)));
	ft_putstr(";40m");
	ft_putnbr(proc->id);
	ft_putstr(" | ld ");
	ft_putnbr(val1);
	ft_putstr(" ");
	ft_putnbr(val2);
	ft_putendl("");
	ft_putstr(C_NONE);
}

void			apply_ld(t_process *process, t_env *env)
{
	t_args		args[3];
	int32_t		val;
	int32_t	reg;
	int32_t	addr;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	addr = process->pc + BYPASS_ARG_ENCODE;
	val = get_args(env->memory, addr, args[0].length);
	val = return_value(process, env->memory, args[0], val);
	addr += args[0].length;
	reg = get_args(env->memory, addr, T_REG);
	if (reg > 0 && reg <= REG_NUMBER)
		process->reg[reg - 1] = val;
	process->nb_cycle -= 5;
	process->pc += BYPASS_ARG_ENCODE + args[0].length + args[1].length;
	process->pc = process->pc % MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
	process->carry = (val == 0);
	if (env->dbg)
		dbg(process, val, reg);
}
