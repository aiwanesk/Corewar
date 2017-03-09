/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:10:08 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:05:37 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** fill process->reg[registre] with value v;
*/

void					apply_lld(t_process *process,
		unsigned char memory[MEM_SIZE], struct s_arg arg)
{
	int				i;
	uint32_t		first;
	uint32_t		reg;

	printf("Instruction lld\n");
	i = -1;
	first = 0;
	while (++i < arg.total_to_read[0]){
		first<<=8;
		first |= memory[PCANDARG + i];
		}
	reg = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		reg<<=8;
		reg |= memory[PCANDARG + i];
		i++;
	}
	if (arg.total_to_read[0] == 1)
		first = process->reg[(first - 1) % REG_NUMBER];
	if (arg.total_to_read[1] == 1)
		reg = process->reg[(reg - 1) % REG_NUMBER];
	process->reg[(reg - 1) % REG_NUMBER] = memory[(process->pc + first)
		% MEM_SIZE];
	process->carry = 1;
	process->pc = (process->pc + i + 2) % MEM_SIZE;
	process->nb_cycle -= 10;
}
