#include "cpu.h"

//TODO voir la doc

void				apply_lldi(t_process *p, uint32_t v1, uint32_t v2, int addr){
	p->reg[addr] = v1 + v2;
	//TODO LE RESTE
}
