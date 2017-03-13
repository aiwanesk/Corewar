/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:06:24 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/10 15:43:32 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** Charge la valeur du premier paramètre dans le registre.
** T_DIR | T_IND, T_REG
*/

void			apply_ld(t_process *process, t_env *env)
{
	t_args		args[3];
	int16_t		val;
	uint32_t	reg;
	uint32_t	addr;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	addr = process->pc + BYPASS_ARG_ENCODE;
	val = (int16_t)get_args(env->memory, addr, args[0].length);
	val = return_value(process, env->memory, args[0], val);
	addr += args[0].length;
	reg = get_args(env->memory, addr, T_REG);
	if (val > 0 || val <= 16)
		process->reg[reg - 1] = val;
	process->nb_cycle -= 5;
	process->pc += BYPASS_ARG_ENCODE + args[0].length + args[1].length;
	process->carry = (val == 0);
}
