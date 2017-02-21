#include "cpu.h"

/*
and : Applique un & (ET bit-à-bit) sur les deux premiers paramètres, et stocke le
résultat dans le registre qui est le 3ème paramètre. Opcode 0x06. Modifie le carry.
*/

//TODO MODIF DU CARRY

void				apply_and(t_process *p, uint32_t v1, uint32_t v2, int addr)
{
	p->reg[addr] = (v1 & v2);
}
