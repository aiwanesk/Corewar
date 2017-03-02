#include "../../includes/cpu.h"

/*
zjmp : Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage des
paramètres derrière cette opération dont l’opcode est de 9. Elle prendra un index,
	et fait un saut à cette adresse si le carry est à 1.
*/

void					apply_zjmp(t_process *p, unsigned char mem[MEM_SIZE], t_arg arg)
{
	int			i;
	uint32_t	dest;

	i = 0;
	dest = 0;
	while (i < arg.total_to_read[0])
	{
		dest += mem[p->pc + 1 + i];
		i++;
	}
	if (p->carry == 1)
		p->pc = dest;
}
