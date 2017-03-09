/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:15:43 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 14:20:07 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** sti : Opcode 11. Prend un registre, et deux index (potentiellement des
** registres). Additionne les deux derniers, utilise cette somme comme une
** adresse ou sera copiée la valeur du premier paramètre.
*/

void				apply_sti(t_process *process, t_env *env)
{
	t_args		args[3];
	uint32_t	val;
	uint32_t	addr;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	addr = process->pc + 1 + args[0].length;
	write_memory(env->memory, 1024, 3145);
	print_memory(env->memory, *env);
	exit(0);
	val = get_args(env->memory, addr, args[1].length);
	addr += args[1].length;
	val += get_args(env->memory, addr, args[2].length);
	protocol_pc(*env, *process, process->pc);
	process->nb_cycle -= 25;
}
