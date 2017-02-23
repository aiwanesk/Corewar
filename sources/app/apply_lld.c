#include "cpu.h"


void					apply_lld(t_process *process, uint32_t v,
		int id_registre)
{
//TODO LOOK PDF
	process->reg[id_registre] = v;
	//TODO changer le carry : est ce que le carry fait 1->0 || 0->1 ou le passe juste a 1
	process->carry = 1;
}
