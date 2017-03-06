/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:11:32 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 15:05:37 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** or : Cette oprocessération est un OU bit-à-bit,
** suivant le même processrinciprocesse que and, son
** oprocesscode est donc évidemment 7.
*/

void	apply_or(t_process *process,
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
	process->reg[reg % REG_NUMBER] = (first | second);
	process->carry = 1;
	process->pc = (process->pc + i + 1) % MEM_SIZE;
}
