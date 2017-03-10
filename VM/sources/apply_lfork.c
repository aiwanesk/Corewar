/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:08:23 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 10:51:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c.
**Crée un nouveau processus, qui hrite des diffrents états de son pre,à part
** son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

void						apply_lfork(t_process *process, t_env *env)
{
	t_args			args[3];
	int16_t			val;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	val = (int16_t)get_args(env->memory, process->pc + 1, args[0].length);
	process->fork.pc = process->pc + val;
	process->fork.isfork = TRUE;
	process->nb_cycle -= 1000;
	process->pc += BYPASS_ARG + args[0].length;
}
