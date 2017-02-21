#include "cpu.h"

/*
st : Prend un registre et un registre ou un indirect, et stocke la valeur du registre
vers le second paramètre. Son opcode est 0x03. Par exemple, st r1, 42 stocke la
valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
*/

void				apply_st(t_process *process, int source, int addr)
{
	process->reg[process->pc + (addr % IDX_MOD)] = process->reg[source];
}
