/*
 * ****************
** HEADER MBA
** ****************
*/


#include "core.h"
#include "libft.h"

//TODO : A del if it useless

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
			if (env.process[a++].pc == (uint32_t)i || i == 15){
				ft_putstr(C_MAGENTA);
				}
		print_hex((uint32_t)memory[i], BASE_16);
		ft_putstr(C_NONE);
		++i;
		write(1,"|", 1);
	}
}
//END TODO

void		write_memory(unsigned char memory[MEM_SIZE], uint32_t addr, uint32_t val)
{
	memory[addr % MEM_SIZE] = convert_endianness32(val);
}
/*
void	read_memory(unsigned char memory[MEM_SIZE], uint32_t addr)
{
	memory[addr % MEM_SIZE] = convert_endianness16(val);
}
*/
uint32_t read_memory(unsigned char *memory, uint32_t addr)
{
	uint32_t val;

		val = (uint32_t)memory[(addr % MEM_SIZE)];
		return (convert_endianness32(val));
}
/*
uint16_t read_memory(unsigned char memory[MEM_SIZE], uint32_t addr)
{
	uint16_t val;

	val = (uint16_t)memory[(addr % MEM_SIZE)];
	return (convert_endianness16(val));
}*/

void print_hex(uintmax_t hex, char *base)
{
	int cmp;
	char str[3];
	int len;

	cmp = 0;
	len = ft_strlen(base);
	cmp =2;
	str[cmp--] = '\0';
	while (cmp >= 0){
		str[cmp--] = base[(hex % len)];
		hex /= len;
	}
	write(1, str, 2);
}

uint32_t convert_endianness32(unsigned int val){
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF00);
	return ((val << 16) | (val >> 16));
}

uint16_t convert_endianness16(uint16_t val){
	return ((val << 8) | (val >> 8));
}
