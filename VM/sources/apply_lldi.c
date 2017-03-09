/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:10:55 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:05:52 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

void				apply_lldi(t_process *process,
		unsigned char mem[MEM_SIZE], t_arg arg)
{
	int			i;
	uint32_t	first;
	uint32_t	second;
	uint32_t	reg;

	printf("Instruction lldi\n");
	i = -1;
	first = 0;
	while (arg.total_to_read[0] > ++i){
		first<<=8;
		first |= mem[PCANDARG + i];
		}
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second<<=8;
		second |= mem[PCANDARG + i];
		i++;
	}
	reg = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1] +
			arg.total_to_read[2])
	{
		reg<<=8;
		reg |= mem[PCANDARG + i];
		i++;
	}
	if (arg.total_to_read[0] == 1)
		first = process->reg[(first -1 ) % REG_NUMBER];
	if (arg.total_to_read[1] == 1)
		second = process->reg[(second -1 ) % REG_NUMBER];
	process->reg[(reg - 1) % REG_NUMBER] = mem[(first + second) % MEM_SIZE];
	process->carry = 1;
	process->pc = (process->pc + i + 2) % MEM_SIZE;
	process->nb_cycle -= 50;
}
