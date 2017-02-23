#include "cpu.h"

/*
 sti : Opcode 11. Prend un registre, et deux index (potentiellement des registres). Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiée la valeur du premier paramètre.
 */

void				apply_sti(t_process *p, uint32_t v1, uint32_t v2, int addr){
	p->reg[addr] = v1 + v2;
	//TODO LE RESTE
}
