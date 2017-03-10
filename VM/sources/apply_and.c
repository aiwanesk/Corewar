/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:04:31 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 16:09:15 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** and : Applique un & (ET bit-à-bit) sur les deux premiers paramètres, et stoc
** ke le
** résultat dans le registre qui est le 3ème paramètre. Opcode 0x06. Modifie
** le carry.
*/

void				apply_and(t_process *process, t_env *env)
{
	t_args		args[3];
	uint32_t	reg;
	uint32_t	pc;
	uint32_t	val1;
	uint32_t	val2;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	pc = process->pc + BYPASS_ARG_ENCODE;
	val1 = get_args(env->memory, pc, args[0].length);
	pc += args[0].length;
	val2 = get_args(env->memory, pc, args[1].length);
	pc += args[1].length;
	reg = get_args(env->memory, pc, args[2].length);
	process->reg[reg - 1] = val1 & val2;
	process->carry = ((val1 & val2) == 0);
	process->nb_cycle -= 6;
	process->pc += BYPASS(args, BYPASS_ARG_ENCODE);
}
