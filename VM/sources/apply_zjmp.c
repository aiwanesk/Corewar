/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:18:38 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 15:43:00 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
**zjmp : Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage des
** paramètres derrière cette opération dont l’opcode est de 9.
*/

void					apply_zjmp(t_process *process, t_env *env)
{
	int16_t			addr;

	addr = (int16_t)get_args(env->memory, process->pc + BYPASS_ARG, T_DIR);
	if (process->carry == 1)
		process->pc = (process->pc + (addr % IDX_MOD)) % MEM_SIZE;
	else
		process->pc = (process->pc + 3) % MEM_SIZE;
	if (process->pc < 0)
		process->pc = (process->pc += MEM_SIZE);
	process->nb_cycle -= 20;
}
