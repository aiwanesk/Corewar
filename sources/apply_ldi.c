#include "cpu.h"

/* 
ldi : ldi, comme son nom l’indique, n’implique nullement de se baigner dans de la crème de marrons, même si son opcode est 0x0a. Au lieu de ça, ca prend 2 index et 1 registre, additionne les 2 premiers, traite ca comme une adresse, y lit une valeur de la taille d’un registre et la met dans le 3eme.
 */

void				apply_ldi(t_process *p, uint32_t v1, uint32_t v2, int addr){
	p->reg[addr] = v1 + v2;
	//TODO LE RESTE
}
