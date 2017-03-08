/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:07:16 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:05:14 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** ldi : ldi,on opcode est 0x0a. Au lieu de ça, ca prend 2 index et 1 registre,
** additionne les 2 premiers, traite ca comme une adresse, y lit une valeur de
** taille d’un registre et la met dans le 3eme.
*/

void				apply_ldi(t_process *process,
		unsigned char mem[MEM_SIZE], t_arg arg)
{
	int			i;
	uint32_t	first;
	uint32_t	second;
	uint32_t	reg;

	printf("Instruction ldi\n");
	i = -1;
	first = 0;
	while (arg.total_to_read[0] > ++i)
		first += mem[PCANDARG + i];
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += mem[PCANDARG + i];
		i++;
	}
	reg = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1] +
			arg.total_to_read[2])
	{
		reg += mem[PCANDARG + i];
		i++;
	}
	if (arg.total_to_read[0] == 1)
		first = process->reg[(first - 1) % REG_NUMBER];
	if (arg.total_to_read[1] == 1)
		second = process->reg[(second - 1) % REG_NUMBER];
	
	process->reg[(reg - 1) % REG_NUMBER] = mem[(first + second) % MEM_SIZE] % IDX_MOD;
	process->pc = (process->pc + i + 2) % MEM_SIZE;
	process->nb_cycle -= 25;
}
