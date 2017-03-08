/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:15:43 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/08 16:47:39 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** sti : Opcode 11. Prend un registre, et deux index (potentiellement des
** registres). Additionne les deux derniers, utilise cette somme comme une
** adresse ou sera copiée la valeur du premier paramètre.
*/

void				apply_sti(t_process *process, t_arg arg, t_env *env)
{
	int			i;
	uint32_t	reg;
	uint32_t	f;
	uint32_t	s;

		printf("Instruction sti\n");
	reg = 0;
	i = -1;
	while (++i < arg.total_to_read[0])
		reg += env->memory[PCANDARG + i];
	f = 0;
	s = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
		f += env->memory[PCANDARG + i++];
	while (i < arg.total_to_read[0] + arg.total_to_read[1] +
			arg.total_to_read[2])
	{
		s += env->memory[PCANDARG + i];
		i++;
	}
	if (arg.total_to_read[1] == 1)
		f = process->reg[(f - 1)  % REG_NUMBER];
	if (arg.total_to_read[2] == 1)
		s = process->reg[(s - 1) % REG_NUMBER];
write_memory(env->memory, (f + s + process->pc) % MEM_SIZE, process->reg[(reg - 1) % REG_NUMBER]);
	process->pc = (process->pc + i + 2) % MEM_SIZE;
	protocol_pc(*env, *process, process->pc);
	process->nb_cycle -= 25;
}
