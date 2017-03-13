/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:07:16 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/10 16:10:49 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"
#include "core.h"

/*
** ldi : ldi,on opcode est 0x0a. Au lieu de ça, ca prend 2 index et 1 registre,
** additionne les 2 premiers, traite ca comme une adresse, y lit une valeur de
** taille d’un registre et la met dans le 3eme.
** T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG
*/

void				apply_ldi(t_process *process, t_env *env)
{
	t_args		args[3];
	uint32_t	addr;
	uint32_t	val;
	int16_t		val1;
	int16_t		val2;

	decode(args, env->memory[process->pc], env->memory[process->pc + 1]);
	addr = process->pc + BYPASS_ARG_ENCODE;
	val1 = get_args(env->memory, addr, args[0].length);
	val1 = return_value(process, env->memory, args[0], val1);
	addr += args[0].length;
	val2 = get_args(env->memory, addr, args[1].length);
	val2 = return_value(process, env->memory, args[1], val2);
	addr += args[1].length;
	addr = get_args(env->memory, addr, T_REG);
	val = process->pc + ((val1 + val2) % IDX_MOD) % MEM_SIZE;
	val = read_memory(env->memory, val);
	if (addr > 0 && addr <= 16)
		process->reg[addr - 1] = val;
	process->pc += BYPASS(args, BYPASS_ARG_ENCODE);
	process->nb_cycle -= 25;
}
