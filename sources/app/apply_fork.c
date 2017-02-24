#include "../../includes/cpu.h"

/*
fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c. Crée un nouveau processus, qui hérite des différents états de son père, à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

void						apply_fork(t_process *p, char *mem[MEM_SIZE], t_arg arg)
{
	int			i;
	uint32_t	f;

	i = 0;
	f = 0;
	while (i < arg.total_to_read[0])
	{
		f += (*mem)[p->pc + 1 + i];
		i++;
	}
	//TODO help please
	p->pc = p->pc + (f % IDX_MOD);
}
