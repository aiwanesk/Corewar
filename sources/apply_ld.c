#include "cpu.h"

/*
 * fill process->reg[registre] with value v;
 * technically i don't have to check the <registre> value , because it's send by the vm.
 */

void					apply_ld(t_process *process, uint32_t v, int registre)
{
	process->reg[registre] = v;
	//TODO changer le carry : est ce que le carry fait 1->0 || 0->1 ou le passe juste a 1
	process->carry = 1;
}
