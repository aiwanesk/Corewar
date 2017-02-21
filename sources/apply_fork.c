#include "cpu.h"

/*
fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c. Crée un nouveau processus, qui hérite des différents états de son père, à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

void						apply_fork(t_process *p, uint32_t dest)
{
	//TODO copy?
	p->pc = p->pc + (dest % IDX_MOD);
}
