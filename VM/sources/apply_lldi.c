/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:10:55 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 17:51:53 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"
#include "core.h"

static void		dbg(t_process *proc, int32_t val1, int32_t val2, int32_t val3)
{
	ft_putstr("P\t");
	ft_putstr("\033[1;");
	ft_putnbr((31 + (proc->idlive % 7)));
	ft_putstr(";40m");
	ft_putnbr(proc->id);
	ft_putstr(" | lldi ");
	ft_putnbr(val1);
	ft_putstr(" ");
	ft_putnbr(val2);
	ft_putstr(" ");
	ft_putnbr(val3);
	ft_putendl("");
	ft_putstr(C_NONE);
}

static void			norme(t_process *process, t_args args[3])
{
	process->pc = BYPASS(args, BYPASS_ARG_ENCODE);
	process->pc %= MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
	process->nb_cycle -= 50;
}

void				apply_lldi(t_process *process, t_env *env)
{
	t_args		args[3];
	int32_t		addr;
	int32_t		val;
	int32_t		val1;
	int32_t		val2;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	addr = process->pc + BYPASS_ARG_ENCODE;
	val1 = get_args(env->memory, addr, args[0].length);
	val1 = return_value(process, env->memory, args[0], val1);
	addr += args[0].length;
	val2 = get_args(env->memory, addr, args[1].length);
	val2 = return_value(process, env->memory, args[1], val2);
	addr += args[1].length;
	addr = get_args(env->memory, addr, T_REG);
	val = process->pc + ((val1 + val2)) % MEM_SIZE;
	val = read_memory(env->memory, val);
	if (addr > 0 && addr <= REG_NUMBER)
		process->reg[addr - 1] = val;
	process->carry = (val == 0);
	norme(process, args);
	if (env->dbg)
		dbg(process, val1, val2, addr);
}
