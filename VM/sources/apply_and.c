/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:04:31 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/08 18:33:34 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** and : Applique un & (ET bit-à-bit) sur les deux premiers paramètres, et stoc
** ke le
** résultat dans le registre qui est le 3ème paramètre. Opcode 0x06. Modifie
** le carry.
*/

void				apply_and(t_process *process,
		unsigned char mem[MEM_SIZE], struct s_arg arg)
{
	int				i;
	uint32_t		first;
	uint32_t		second;
	uint32_t		dest;

	printf("Instruction And\n");
//	printf("apply and\n");
	i = -1;
	first = 0;
	while (++i < arg.total_to_read[0])
		first += mem[(PCANDARG + i) % MEM_SIZE];
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += mem[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	dest = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1] +
			arg.total_to_read[2])
	{
		dest += mem[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	if (arg.total_to_read[0] == 1)
		first = process->reg[(first - 1) % REG_NUMBER];
	if (arg.total_to_read[1] == 1)
		second = process->reg[(second - 1) % REG_NUMBER];
	
//	printf("i debug = %d\n", (first & second));
//	if ((first & second) != 0)
		process->carry = 1;
//	else
//		process->carry = 0;
		
	process->reg[(dest - 1) % REG_NUMBER] = (first & second);
	process->pc = (process->pc + i + 2) % MEM_SIZE;
	process->nb_cycle -= 6;
}
