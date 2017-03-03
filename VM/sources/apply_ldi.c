/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:07:16 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/03 16:36:28 by aiwanesk         ###   ########.fr       */
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
	process->reg[reg % REG_NUMBER] = mem[(first + second) % MEM_SIZE] % IDX_MOD;
}
