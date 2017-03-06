/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:06:24 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:03:28 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

void					apply_ld(t_process *process,
		unsigned char memory[MEM_SIZE], struct s_arg arg)
{
	int				i;
	uint32_t		first;
	uint32_t		reg;

	i = 0;
	first = 0;
	while (i < arg.total_to_read[0])
	{
		first += memory[PCANDARG + i];
		i++;
	}
	reg = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		reg += memory[PCANDARG + i];
		i++;
	}
	if (arg.total_to_read[0] == 1)
		first = process->reg[first % REG_NUMBER];
	if (arg.total_to_read[1] == 1)
		reg = process->reg[reg % REG_NUMBER];
	process->memory[reg % REG_NUMBER] = process->memory[(process->pc +
			(first % IDX_MOD)) % MEM_SIZE];
	process->carry = 1;
	process->pc = (process->pc + i + 1) % MEM_SIZE;
	process->nb_cycle -= 5;
}
