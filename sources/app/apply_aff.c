#include "../../includes/cpu.h"

void					apply_aff(t_process *p, char mem[MEM_SIZE], t_arg arg)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (i < arg.total_to_read[0])
	{
		f += mem[p->pc + 1 + i];
		i++;
	}
	ft_putnbr(p->reg[f] % 256);
}
