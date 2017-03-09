/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:11:32 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/08 16:50:46 by aiwanesk         ###   ########.fr       */
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

	printf("Instruction or\n");
	i = -1;
	first = 0;
	while (++i < arg.total_to_read[0]){
		first<<=8;
		first |= memory[(PCANDARG + i) % MEM_SIZE];
		}
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second<<=8;
		second |= memory[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	reg = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1] +
			arg.total_to_read[2])
	{
		reg<<=8;
		reg |= memory[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	process->reg[reg % REG_NUMBER] = (first | second);
	if ((first | second) == process->reg[reg % REG_NUMBER])
		process->carry = 1;
	else
		process->carry = 0;
	process->pc = (process->pc + i + 2) % MEM_SIZE;
	process->nb_cycle -= 6;
}
