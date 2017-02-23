#include "../../includes/cpu.h"

/*
st : Prend un registre et un registre ou un indirect, et stocke la valeur du registre
vers le second paramètre. Son opcode est 0x03. Par exemple, st r1, 42 stocke la
valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
*/

void				apply_st(t_process *process, char *mem[MEM_SIZE], struct s_arg arg)
{
	int		i;
	int		reg;
	int		second;

	i = 0;
	reg = 0;
	while (i < arg.total_to_read[0])
	{
		reg += (*mem)[PCANDARG + i];
		i++;
	}
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += (*mem)[PCANDARG + i];
		i++;
	}
	(*mem)[process->pc + (second % IDX_MOD)] = process->reg[reg];
}
