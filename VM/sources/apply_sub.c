/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:16:56 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 15:05:44 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** add : Opcode 4. Prend trois registres, additionne les 2 premiers, et met le r
** dans le troisième, juste avant de modifier le carry.
*/

void				apply_sub(struct s_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg)
{
	int					i;
	uint32_t			first;
	uint32_t			second;
	uint32_t			dest;

	i = -1;
	first = 0;
	while (++i < arg.total_to_read[0])
		first += memory[(PCANDARG + i) % MEM_SIZE];
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += memory[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	dest = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1] +
			arg.total_to_read[2])
	{
		dest += memory[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	process->reg[dest % REG_NUMBER] = process->reg[first % REG_NUMBER]
		- process->reg[second % REG_NUMBER];
	process->carry = 1;
	process->pc = (process->pc + i + 1) % MEM_SIZE;
}
