/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:55:17 by mbarbari          #+#    #+#             */
/*   Updated: 2017/03/20 10:51:10 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

static t_op		*return_t_op(void)
{
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

	return (op);
}

int				length_label(int32_t opcode)
{
	int			i;
	t_op		*op;

	op = return_t_op();
	i = 0;
	while (i < 17)
	{
		if (op[i].opcode == opcode)
			return (op[i].length);
		++i;
	}
	return (0);
}

int32_t		get_args(unsigned char *memory, int32_t addr, int oct)
{
	int32_t		val;
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

int32_t		return_value(t_process *process, unsigned char *mem,
		t_args args, int32_t val)
{
	if (args.arg == REG_CODE && (val > 0 && val <= 16))
		return (process->reg[val - 1]);
	else if (args.arg == IND_CODE)
		return ((int16_t)mem[(process->pc + (val % IDX_MOD)) % MEM_SIZE]);
	else if (args.arg == DIR_CODE)
	{
		if (args.length == 2)
			return ((int16_t)val);
		return (val);
	}
	return (val);
}
