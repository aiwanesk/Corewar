#include "cpu.h"

void					apply_aff(t_process *p, uint32_t v)
{
	write(1, &(p->reg[v] % 256), 1);
}
