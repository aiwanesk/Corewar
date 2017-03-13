/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:01:44 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 15:36:31 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** add : Opcode 4. Prend trois registres, additionne les 2 premiers,
** et met le résultat
** dans le troisième, juste avant de modifier le carry.
*/

void			apply_add(t_process *process, t_env *env)
{
	uint32_t		reg[3];
	uint32_t		val;

	reg[0] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE, T_REG);
	reg[1] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE + 1, T_REG);
	reg[2] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE + 2, T_REG);
	val = process->reg[reg[0] - 1] + process->reg[reg[1] - 1];
	if (val > 0 || val <= 16)
	{
		process->reg[reg[2] - 1] = val;
		process->carry = (val == 0);
	}
	else
		process->carry = FALSE;
	process->nb_cycle -= 10;
	process->pc += BYPASS_ARG_ENCODE + (3 * T_REG);
}
