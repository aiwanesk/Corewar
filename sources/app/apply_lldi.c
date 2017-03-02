#include "../../includes/cpu.h"

/* 
ldi : ldi, comme son nom l’indique, n’implique nullement de se baigner dans de la crème de marrons, même si son opcode est 0x0a. Au lieu de ça, ca prend 2 index et 1 registre, additionne les 2 premiers, traite ca comme une adresse, y lit une valeur de la taille d’un registre et la met dans le 3eme.
 */

void				apply_lldi(t_process *process, unsigned char mem[MEM_SIZE], t_arg arg)
{
	int			i;
	uint32_t	first;
	uint32_t	second;
	uint32_t	reg;

	i = 0;
	first = 0;
	while (arg.total_to_read[0] > i)
	{
		first += mem[PCANDARG + i];
		i++;
	}
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += mem[PCANDARG + i];
		i++;
	}
	while (i < arg.total_to_read[0] + arg.total_to_read[1] + arg.total_to_read[2])
	{
		reg += mem[PCANDARG + i];
		i++;
	}
	//TODO clairement pas sur du comportement de celui la 
	process->reg[reg] = mem[first + second] % IDX_MOD;
}
