/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:45:01 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 18:35:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include <stdio.h>

void		print_memory(unsigned char memory[MEM_SIZE], t_env env)
{
	int			i;
	int32_t		a;

	i = 0;
	while (i < MEM_SIZE)
	{
		a = 0;
		if (i > 0 && (i % 64) == 0)
			write(1, "\n", 1);
		a = (int)env.nbprocess;
		while (--a > -1)
		{
			if (env.process[a].pc == i)
			{
				ft_putstr("\033[1;");
				ft_putnbr((31 + env.process[a].idlive));
				ft_putstr(";40m");
			}
		}
		print_hex((int32_t)memory[i], BASE_16);
		ft_putstr(C_NONE);
		++i;
		write(1, " ", 1);
	}
}

void		print_hex(uintmax_t hex, char *base)
{
	int		cmp;
	char	str[3];
	int		len;

	cmp = 0;
	len = ft_strlen(base);
	cmp = 2;
	str[cmp--] = '\0';
	while (cmp >= 0)
	{
		str[cmp--] = base[(hex % len)];
		hex /= len;
	}
	write(1, str, 2);
}

void		write_memory(unsigned char *memory, int32_t addr, int32_t val)
{
	int16_t		a;

	a = (int16_t)addr;
	memory[(((a < 0) ? a + MEM_SIZE : a) + 3) % MEM_SIZE] =
		((val >> 0) & 0xFF);
	memory[(((a < 0) ? a + MEM_SIZE : a) + 2) % MEM_SIZE] =
		((val >> 8) & 0xFF);
	memory[(((a < 0) ? a + MEM_SIZE : a) + 1) % MEM_SIZE] =
		((val >> 16) & 0xFF);
	memory[(((a < 0) ? a + MEM_SIZE : a) + 0) % MEM_SIZE] =
		((val >> 24) & 0xFF);
}

int32_t	read_memory(unsigned char *memory, int32_t addr)
{
	int32_t	val;
	int32_t	tmp;
	int16_t		a;

	a = (int16_t)addr;
	val = 0;
	tmp = memory[(((a < 0) ? a + MEM_SIZE : a) + 3) % MEM_SIZE];
	tmp <<= 24;
	val |= tmp;
	tmp = memory[(((a < 0) ? a + MEM_SIZE : a) + 2) % MEM_SIZE];
	tmp <<= 16;
	val |= tmp;
	tmp = memory[(((a < 0) ? a + MEM_SIZE : a) + 1) % MEM_SIZE];
	tmp <<= 8;
	val |= tmp;
	tmp = memory[(((a < 0) ? a + MEM_SIZE : a) + 0) % MEM_SIZE];
	val |= tmp;
	return (val);
}
