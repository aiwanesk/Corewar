#include "cpu.h"

/*
xor : Fait comme and avec un OU exclusif. Comme vous l’aurez deviné, son opcode
en octal est 10.
*/

//TODO MODIF DU CARRY

void                apply_xor(t_process *p, uint32_t v1, uint32_t v2, int addr)
{
    p->reg[addr] = (v1 ^ v2);
}
