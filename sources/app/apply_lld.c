#include "../../includes/cpu.h"

/*
 * fill process->reg[registre] with value v;
 * technically i don't have to check the <registre> value , because it's send by the vm.
 */

void					apply_lld(t_process *process, unsigned char memory[MEM_SIZE], struct s_arg arg)
{
	int				i;
	uint32_t		first;
	uint32_t		reg;

	i = 0;
	first = 0;
	while (i < arg.total_to_read[0])
	{
		first += memory[PCANDARG + i];
		i++;
	}
	reg = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		reg += memory[PCANDARG + i];
		i++;
	}
	if (arg.total_to_read[0] == 1)
		first = process->reg[reg % REG_NUMBER];
	if (arg.total_to_read[1] == 1)
		reg = process->reg[reg % REG_NUMBER];
	process->reg[reg % REG_NUMBER] = process->memory[(process->pc + first) % MEM_SIZE];
	process->carry = 1;
}
