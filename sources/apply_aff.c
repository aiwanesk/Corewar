#include "cpu.h"

void					apply_aff(t_process *p, uint32_t v)
{
	ft_putnbr(p->reg[v] % 256);
}
