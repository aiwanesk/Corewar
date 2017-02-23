#include "cpu.h"

/*
add : Opcode 4. Prend trois registres, additionne les 2 premiers, et met le résultat
dans le troisième, juste avant de modifier le carry.
*/

void				apply_add(struct s_process *p, uint32_t v1, uint32_t v2, int addr)
{
	p->reg[addr] = v1 + v2;
}
