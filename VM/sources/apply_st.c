/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:13:03 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 17:51:04 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** st : Prend un registre et un registre ou un indirect, et stocke la valeur du
** vers le second paramètre. Son opcode est 0x03. Par exemple, st r1, 42 stocke
** valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
*/

static void		dbg(t_process *proc, int32_t val1, int32_t val2)
{
	ft_putstr("P\t");
	ft_putstr("\033[1;");
	ft_putnbr((31 + (proc->idlive % 7)));
	ft_putstr(";40m");
	ft_putnbr(proc->id);
	ft_putstr(" | st ");
	ft_putnbr(val1);
	ft_putstr(" ");
	ft_putnbr(val2);
	ft_putendl("");
	ft_putstr(C_NONE);
}

static void		norme(t_process *process, t_args args[3])
{
	process->nb_cycle -= 5;
	process->pc += BYPASS_ARG_ENCODE + args[0].length + args[1].length;
	process->pc %= MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
}

void			apply_st(t_process *process, t_env *env)
{
	t_args		args[3];
	int32_t		reg;
	int32_t		addr;
	int32_t		pc;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	pc = process->pc + 2;
	reg = get_args(env->memory, pc, T_REG);
	pc += args[0].length;
	addr = (int16_t)get_args(env->memory, pc, args[1].length);
	if (args[1].arg == REG_CODE)
	{
		if (addr > 0 && addr <= REG_NUMBER && reg > 0 && reg <= REG_NUMBER)
			process->reg[addr - 1] = process->reg[reg - 1];
	}
	else if (reg > 0 && reg <= REG_NUMBER)
	{
		write_memory(env->memory, process->pc + (addr % IDX_MOD),
				process->reg[reg - 1]);
		protocol_mem(*env, *process, process->pc + (addr % IDX_MOD));
	}
	norme(process, args);
	if (env->dbg)
		dbg(process, reg, addr);
}
