/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_xor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:17:51 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:04:57 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** xor : Cette oprocessération est un OU exclusif bit-à-bit, suivant le même
** processrinciprocesse que and, son
** oprocesscode est donc évidemment 8.
*/

void	apply_xor(t_process *process,
		unsigned char memory[MEM_SIZE], struct s_arg arg)
{
	int				i;
	uint32_t		first;
	uint32_t		second;
	uint32_t		reg;

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
	reg = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1] +
			arg.total_to_read[2])
	{
		reg += memory[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	process->reg[reg % REG_NUMBER] = (first ^ second);
	process->carry = 1;
	process->pc = (process->pc + i + 1) % MEM_SIZE;
	process->nb_cycle -= 6;
}
