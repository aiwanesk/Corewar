/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:55:17 by mbarbari          #+#    #+#             */
/*   Updated: 2017/03/10 10:38:19 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

int				length_label(uint32_t opcode)
{
	int			i;
	static t_op		op[17] = {
		{0x01, 4},
		{0x02, 4},
		{0x03, 0},
		{0x04, 0},
		{0x05, 0},
		{0x06, 4},
		{0x07, 4},
		{0x08, 4},
		{0x09, 2},
		{0x0A, 2},
		{0x0B, 2},
		{0x0C, 2},
		{0x0D, 4},
		{0x0E, 2},
		{0x0F, 2},
		{0x10, 0},
		{0x00, 0},
	};

	i = 0;
	while (i < 17)
	{
		if (op[i].opcode == opcode)
			return (op[i].length);
		++i;
	}
	return (0);
}

uint32_t		get_args(unsigned char *memory, uint32_t addr, int oct)
{
	uint32_t		val;
	int				i;

	val = 0;
	i = 0;
	while (i < oct)
	{
		val <<= 8;
		val |= (unsigned int)(*(memory + addr + i));
		++i;
	}
	return (val);
}

uint32_t	return_value(t_process *process, unsigned char *mem, t_args args,
													uint32_t val)
{
	if (args.arg == REG_CODE)
		return (process->reg[val - 1]);
	else if (args.arg == IND_CODE)
		return (mem[(process->pc + (val % IDX_MOD)) % MEM_SIZE]);
	else
		return (val);
}
