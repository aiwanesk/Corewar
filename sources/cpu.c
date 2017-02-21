#include "cpu.h"

t_process				cpu(t_process process)
{
	if (process.pc == 1)
		apply_live(&process);
	else if (process.pc == 2)
		apply_ld(&process, process.reg[0], process.reg[1]);
	else if (process.pc == 3)
		apply_st(&process, process.reg[0], process.reg[1]);
	else if (process.pc == 4)
		apply_add(&process, process.reg[0], process.reg[1], process.reg[2]);
	else if (process.pc == 5)
		apply_sub(&process, process.reg[0], process.reg[1], process.reg[2]);
	else if (process.pc == 6)
		apply_and(&process, process.reg[0], process.reg[1], process.reg[2]);
	else if (process.pc == 7)
		apply_or(&process, process.reg[0], process.reg[1], process.reg[2]);
	else if (process.pc == 8)
		apply_xor(&process, process.reg[0], process.reg[1], process.reg[2]);
	else if (process.pc == 9)
		apply_zjmp(&process, process.reg[0]);
	return (process);
}
