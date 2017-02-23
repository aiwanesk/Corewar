#include "cpu.h"

/*
 * sub : Pareil que add, mais l’opcode est 0b101, et utilise une soustraction.
 */

void				apply_sub(t_process *p, uint32_t v1, uint32_t v2, int addr)
{
	p->reg[addr] = v1 - v2;
}
