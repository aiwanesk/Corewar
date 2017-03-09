/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:15:43 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/08 18:28:14 by aiwanesk         ###   ########.fr       */
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
	{
		f <<= 8;
		f |= env->memory[PCANDARG + i++];
	}
	while (i < arg.total_to_read[0] + arg.total_to_read[1] +
			arg.total_to_read[2])
	{
		s <<= 8;
		s |= env->memory[PCANDARG + i];
		i++;
	}
//	printf("f = %x s = %x f + s = %x reg = %x\n", f ,s ,f +s , process->reg[(reg -1 ) % MEM_SIZE]);
	if (arg.total_to_read[1] == 1)
		f = process->reg[(f - 1)  % REG_NUMBER];
	if (arg.total_to_read[2] == 1)
		s = process->reg[(s - 1) % REG_NUMBER];
	uint32_t *bit;
	bit = (uint32_t *)malloc(sizeof(uint32_t) * 4);
	assign(process->reg[(reg - 1) % MEM_SIZE], &bit);
	int j;
	for (j = 0; j < 4; j++){
//		printf("%d\n", bit[i]);
		env->memory[(f + s + process->pc + j) % MEM_SIZE] = bit[j];
	}
	process->pc = (process->pc + i + 2) % MEM_SIZE;
	protocol_pc(*env, *process, process->pc);
	process->nb_cycle -= 25;
	free(bit);
}
