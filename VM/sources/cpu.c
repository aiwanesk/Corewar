/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:20:54 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:07:01 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cpu.h"

static t_process		norme(t_process process, t_arg arg, t_env *env)
{
	if (env->memory[process.pc] == 9 && process.nb_cycle >= 20)
		apply_zjmp(&process, env->memory, arg);
	else if (env->memory[process.pc] == 10 && process.nb_cycle >= 25)
		apply_ldi(&process, env->memory, arg);
	else if (env->memory[process.pc] == 11 && process.nb_cycle >= 25)
		apply_sti(&process, arg, env);
	else if (env->memory[process.pc] == 12 && process.nb_cycle >= 800)
		apply_fork(&process, env, arg);
	else if (env->memory[process.pc] == 13 && process.nb_cycle >= 10)
		apply_lld(&process, env->memory, arg);
	else if (env->memory[process.pc] == 14 && process.nb_cycle >= 50)
		apply_lldi(&process, env->memory, arg);
	else if (env->memory[process.pc] == 15 && process.nb_cycle >= 1000)
		apply_lfork(&process, env, arg);
	else if (env->memory[process.pc] == 16 && process.nb_cycle >= 2)
		apply_aff(&process, env->memory, arg);
	else if (env->memory[process.pc] > 16 || env->memory[process.pc] == 0)
	{
		process.nb_cycle -= 1;
		process.pc += 1;
	}
	return (process);
}

t_process				cpu(t_process process, t_env *env)
{
	t_arg		arg;

	arg = parsing_request(&process, env->memory);
//	printf("pos = [%d]---id = [%d]\n", process.pc, process.id);
//	if (env->memory[process.pc] < 17 && env->memory[process.pc] != 0)
//		printf("id  = %d\n", process.id);
	if (env->memory[process.pc] == 1 && process.nb_cycle >= 10)
		apply_live(&process, env->memory, env);
	else if (env->memory[process.pc] == 2 && process.nb_cycle >= 5)
		apply_ld(&process, env->memory, arg);
	else if (env->memory[process.pc] == 3 && process.nb_cycle >= 5)
		apply_st(&process, arg, env);
	else if (env->memory[process.pc] == 4 && process.nb_cycle >= 10)
		apply_add(&process, env->memory, arg);
	else if (env->memory[process.pc] == 5 && process.nb_cycle >= 10)
		apply_sub(&process, env->memory, arg);
	else if (env->memory[process.pc] == 6 && process.nb_cycle >= 6)
		apply_and(&process, env->memory, arg);
	else if (env->memory[process.pc] == 7 && process.nb_cycle >= 6)
		apply_or(&process, env->memory, arg);
	else if (env->memory[process.pc] == 8 && process.nb_cycle >= 6)
		apply_xor(&process, env->memory, arg);
	else
		return (norme(process, arg, env));
	return (process);
}
