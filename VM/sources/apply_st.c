/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:13:03 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 15:42:27 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** st : Prend un registre et un registre ou un indirect, et stocke la valeur du
** vers le second paramètre. Son opcode est 0x03. Par exemple, st r1, 42 stocke
** valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
*/

static void		norme(t_process *process, t_args args[3])
{
	process->nb_cycle -= 5;
	process->pc += BYPASS_ARG_ENCODE + args[0].length + args[1].length;
}

void			apply_st(t_process *process, t_env *env)
{
	t_args		args[3];
	int32_t	reg;
	int16_t		addr;
	int32_t	pc;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	pc = process->pc + 2;
	reg = get_args(env->memory, pc, T_REG);
	pc += args[0].length;
	addr = (int16_t)get_args(env->memory, pc, args[1].length);
	if (args[1].arg == REG_CODE)
	{
			if (addr > 0 && addr <= 16 && reg > 0 && reg <= 16)
				process->reg[addr - 1] = process->reg[reg - 1];
	}
	else if (reg > 0 && reg <= 16)
	{
		write_memory(env->memory, process->pc + (addr % IDX_MOD),
				process->reg[reg - 1]);
		protocol_mem(*env, *process, process->pc + (addr % IDX_MOD));
	}
	norme(process, args);
}
