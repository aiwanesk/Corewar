#include "cpu.h"

/*or : Cette opération est un OU bit-à-bit, suivant le même principe que and, son
 * opcode est donc évidemment 7.
 */

//TODO MODIF DU CARRY

void                apply_or(t_process *p, uint32_t v1, uint32_t v2, int addr)
{
    p->reg[addr] = (v1 | v2);
}
