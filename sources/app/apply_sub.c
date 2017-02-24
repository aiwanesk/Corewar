#include "../../includes/cpu.h"

/*
add : Opcode 4. Prend trois registres, additionne les 2 premiers, et met le résultat
dans le troisième, juste avant de modifier le carry.
*/

void				apply_sub(struct s_process *process, char memory[MEM_SIZE], t_arg arg)
{
	int					i;
	uint32_t			first;
	uint32_t			second;
	uint32_t			dest;

	i = 0;
	first = 0;
	while (i < arg.total_to_read[0])
	{
		first += memory[PCANDARG + i];
		i++;
	}
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += memory[PCANDARG + i];
		i++;
	}
	dest = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1] + arg.total_to_read[2])
	{
		dest += memory[PCANDARG + i];
		i++;
	}
	process->reg[dest] = process->reg[first] - process->reg[second];
	process->carry = 1;
}
