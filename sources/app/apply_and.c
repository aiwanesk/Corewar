#include "../../includes/cpu.h"

/*
and : Applique un & (ET bit-à-bit) sur les deux premiers paramètres, et stocke le
résultat dans le registre qui est le 3ème paramètre. Opcode 0x06. Modifie le carry.
*/

void				apply_and(t_process *process, char mem[MEM_SIZE], struct s_arg arg)
{
	int				i;
	uint32_t		first;
	uint32_t		second;
	uint32_t		dest;

	i = 0;
	first = 0;
	while (i < arg.total_to_read[0])
	{
		first += mem[PCANDARG + i];
		i++;
	}
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += mem[PCANDARG + i];
		i++;
	}
	while (i < arg.total_to_read[0] + arg.total_to_read[1] + arg.total_to_read[2])
	{
		dest += mem[PCANDARG + i];
		i++;
	}
	process->reg[dest] = (first ^ second);
	process->carry = 1;
}
