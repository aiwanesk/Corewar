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

	reg[0] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE, T_REG);
	dprintf(1, "Test reg : %u\n", reg[0]);
	reg[1] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE + 1, T_REG);
	dprintf(1, "Test reg : %u\n", reg[0]);
	reg[2] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE + 2, T_REG);
	dprintf(1, "Test reg : %u\n", reg[0]);
	process->reg[reg[2]] = process->reg[reg[0]] + process->reg[reg[1]];
}
