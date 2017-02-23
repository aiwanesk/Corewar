#include "cpu.h"

/*
zjmp : Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage des
paramètres derrière cette opération dont l’opcode est de 9. Elle prendra un index,
	et fait un saut à cette adresse si le carry est à 1.
*/

void					apply_zjmp(t_process *p, uint32_t dest)
{
	if (p->carry == 1)
		p->pc = dest;
}
