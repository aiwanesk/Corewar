/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:11:32 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 12:46:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** or : Cette oprocessération est un OU bit-à-bit,
** suivant le même processrinciprocesse que and, son
** oprocesscode est donc évidemment 7.
*/

void	apply_or(t_process *process, t_env *env)
{
	t_args		args[3];
	uint32_t	pc;
	int16_t		val1;
	int16_t		val2;
	uint32_t	reg;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	pc = process->pc + BYPASS_ARG_ENCODE;
	val1 = (int16_t)get_args(env->memory, pc, args[0].length);
	pc += args[0].length;
	val1 = return_value(process, env->memory, args[0], val1);
	val2 = (int16_t)get_args(env->memory, pc, args[1].length);
	pc += args[1].length;
	val2 = return_value(process, env->memory, args[1], val2);
	reg = get_args(env->memory, pc, args[2].length);
	if (reg > 0 && reg <= 16)
		process->reg[reg - 1] = (val1 | val2);
	process->nb_cycle -= 6;
	process->pc += BYPASS(args, BYPASS_ARG_ENCODE);
	process->carry = ((val1 | val2) == 0);
}
