/*
 * ****************
** HEADER MBA
** ****************
*/


#include "core.h"
#include "libft.h"

//TODO : A del if it useless

void		print_hex(uintmax_t hex, char *base)
{
	int			cmp;
	char		str[3];
	int			len;

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

void		print_memory(unsigned char memory[MEM_SIZE])
{
	int		i;

	i = 0;
	int j = 0;
	while (i < MEM_SIZE)
	{
		if (i > 0 && (i % 64) == 0)
			write(1, "\n", 1);
		print_hex((uint32_t)memory[i], BASE_16);
		++i;
		++j;
		if (j == 1){
			write(1,"|", 1);
			j = 0;
		}
	}
}
//END TODO

void		write_memory(unsigned char memory[MEM_SIZE], uint32_t addr, uint32_t val)
{
	memory[addr % MEM_SIZE] = val;
}

uint32_t	read_memory(unsigned char memory[MEM_SIZE], uint32_t addr)
{
	return (memory[(addr % MEM_SIZE)]);
}

void		cpy_memory(unsigned char memory[MEM_SIZE], unsigned char cpy[MEM_SIZE])
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		memory[i] = cpy[i];
		++i;
	}
}
