/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:04:19 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 12:47:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

void			apply_aff(t_process *process, t_env *env)
{
	t_args		args[3];
	int32_t	pc;
	int32_t	reg;
	char		val;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	pc = process->pc + BYPASS_ARG_ENCODE;
	reg = get_args(env->memory, pc, args[0].length);
	if (reg > 0 && reg <= 16)
	{
		val = (process->reg[reg - 1] & 0xFF);
		write(1, &val, 1);
	}
	process->nb_cycle -= 2;
	process->pc += BYPASS_ARG_ENCODE + args[0].length;
}
