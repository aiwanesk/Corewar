#include "../../includes/cpu.h"

/*
 sti : Opcode 11. Prend un registre, et deux index (potentiellement des registres). Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiée la valeur du premier paramètre.
 */

void				apply_sti(t_process *process, t_arg arg)
{
	int			i;
	uint32_t	reg;
	uint32_t	f;
	uint32_t	s;

	reg = 0;
	i = 0;
	while (i < arg.total_to_read[0])
	{
		reg += process->memory[PCANDARG + i];
		i++;
	}
	f = 0;
	s = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		f += process->memory[PCANDARG + i];
		i++;
	}
	while (i < arg.total_to_read[0] + arg.total_to_read[1] + arg.total_to_read[2])
	{
		s += process->memory[PCANDARG + i];
		i++;
	}
	if (arg.total_to_read[1] == 1)
		f = process->reg[f];
	if (arg.total_to_read[2] == 1)
		s = process->reg[s];
	process->memory[(f + s)  % MEM_SIZE] = process->reg[reg % REG_NUMBER];
}
