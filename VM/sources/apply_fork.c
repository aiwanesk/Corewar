/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:05:51 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 10:51:13 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c.
** Crée un nouveau processus, qui hérite des différents états de son père,
** à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

void						apply_fork(t_process *process, t_env *env)
{
	int16_t			val;

	val = (int16_t)get_args(env->memory, process->pc + 1, T_DIR);
	process->fork.pc = (process->pc + (val % IDX_MOD)) % MEM_SIZE;
	process->fork.isfork = TRUE;
	process->nb_cycle -= 800;
	process->pc += BYPASS_ARG + T_DIR;
}
