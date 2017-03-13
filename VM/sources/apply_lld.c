/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:10:08 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 12:47:16 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** fill process->reg[registre] with value v;
*/

void			apply_lld(t_process *process, t_env *env)
{
	t_args		args[3];
	int16_t		val;
	uint32_t	reg;
	uint32_t	addr;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	addr = process->pc + BYPASS_ARG_ENCODE;
	val = (int16_t)get_args(env->memory, addr, args[0].length);
	if (args[0].arg == REG_CODE && (val > 0 && val <= 16))
		val = process->reg[val - 1];
	else if (args[0].arg == IND_CODE)
		val = env->memory[((process->pc + val)) % MEM_SIZE];
	addr += args[0].length;
	reg = get_args(env->memory, addr, T_REG);
	if (reg > 0 && reg <= 16)
		process->reg[reg - 1] = val;
	process->nb_cycle -= 10;
	process->pc += BYPASS_ARG_ENCODE + args[0].length + args[1].length;
	process->carry = (val == 0);
}
