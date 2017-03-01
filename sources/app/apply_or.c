#include "../../includes/cpu.h"

/*or : Cette oprocessération est un OU bit-à-bit, suivant le même processrinciprocesse que and, son
 * oprocesscode est donc évidemment 7.
 */

void                apply_or(t_process *process, char memory[MEM_SIZE], struct s_arg arg)
{
	int				i;
	uint32_t		first;
	uint32_t		second;
	uint32_t		reg;

	//TODO CHECK les overflows sur la taille de la memoire 
	i = 0;
	first = 0;
//	printf("arg[0] = %d\n", arg.total_to_read[0]);
//	printf("arg[1] = %d\n", arg.total_to_read[1]);
//	printf("arg[2] = %d\n", arg.total_to_read[2]);
	while (i < arg.total_to_read[0])
	{
		first += memory[(PCANDARG + i) % MEM_SIZE];
	//	printf("pc = %d memory[%u]\n", (PCANDARG + i) % MEM_SIZE, memory[(PCANDARG + i) % MEM_SIZE]);
		i++;
	}
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += memory[(PCANDARG + i) % MEM_SIZE];
//		printf("pc = %d memory[%u]\n", (PCANDARG + i) % MEM_SIZE, memory[(PCANDARG + i) % MEM_SIZE]);
		i++;
	}
	reg = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1] + arg.total_to_read[2])
	{
		reg += memory[(PCANDARG + i) % MEM_SIZE];
//		printf("pc = %d memory[%u]\n", (PCANDARG + i) % MEM_SIZE, memory[(PCANDARG + i) % MEM_SIZE]);
		i++;
	}
//	printf("debug = f[%d] s[%d] reg[%d]\n", first,second,reg);
	process->reg[reg % REG_NUMBER] = (first | second);
	process->carry = 1;
}
