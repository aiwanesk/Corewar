/*
 * ****************
** HEADER MBA
** ****************
*/


#include "core.h"
#include "libft.h"
#include <stdio.h>

void		print_memory(unsigned char memory[MEM_SIZE], t_env env)
{
	int		i;
	uint32_t a;

	i = 0;
	while (i < MEM_SIZE)
	{
		a = 0;
		if (i > 0 && (i % 64) == 0)
			write(1, "\n", 1);
		while (a < env.nbprocess)
			if (env.process[a++].pc == i)
				ft_putstr(C_MAGENTA);
		print_hex((uint32_t)memory[i], BASE_16);
		ft_putstr(C_NONE);
		++i;
		write(1,"|", 1);
	}
}

void		print_hex(uintmax_t hex, char *base)
{
	int cmp;
	char str[3];
	int len;

	cmp = 0;
	len = ft_strlen(base);
	cmp = 2;
	str[cmp--] = '\0';
	while (cmp >= 0){
		str[cmp--] = base[(hex % len)];
		hex /= len;
	}
	write(1, str, 2);
}

void write_memory(unsigned char *memory, uint32_t addr, uint32_t val)
{
	int16_t		a;

	a = (int16_t)addr;
	memory[(((a < 0) ? a + MEM_SIZE: a) + 3) % MEM_SIZE] = ((val >> 24) & 0xFF);
	memory[(((a < 0) ? a + MEM_SIZE: a) + 2) % MEM_SIZE] = ((val >> 16) & 0xFF);
	memory[(((a < 0) ? a + MEM_SIZE: a) + 1) % MEM_SIZE] = ((val >> 8) & 0xFF);
	memory[(((a < 0) ? a + MEM_SIZE: a) + 0) % MEM_SIZE] = ((val >> 0) & 0xFF);
}

uint32_t	read_memory(unsigned char *memory, uint32_t addr)
{
	uint32_t	val;
	uint32_t	tmp;
	int16_t		a;

	a = (int16_t)addr;
	val = 0;
	tmp = memory[(((a < 0) ? a + MEM_SIZE: a) + 3) % MEM_SIZE];
	tmp <<= 24;
	val |= tmp;
	tmp = memory[(((a < 0) ? a + MEM_SIZE: a) + 2) % MEM_SIZE];
	tmp <<= 16;
	val |= tmp;
	tmp = memory[(((a < 0) ? a + MEM_SIZE: a) + 1) % MEM_SIZE];
	tmp <<= 8;
	val |= tmp;
	tmp = memory[(((a < 0) ? a + MEM_SIZE: a) + 0) % MEM_SIZE];
	val |= tmp;
	return (val);
}
