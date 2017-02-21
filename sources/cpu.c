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
	else if (process.pc == 10)
		apply_ldi(&process, process.reg[0], process.reg[1], process.reg[2]);
	else if (process.pc == 11)
		apply_sti(&process, process.reg[0], process.reg[1], process.reg[2]);
	else if (process.pc == 12)
		apply_fork(&process, process.reg[0]);
	else if (process.pc == 13)
		apply_lld(&process, process.reg[0], process.reg[1]);
	else if (process.pc == 14)
		apply_lldi(&process, process.reg[0], process.reg[1], process.reg[2]);
	else if (process.pc == 15)
		apply_lfork(&process, process.reg[0]);
	else if (process.pc == 16)
		apply_aff(&process, process.reg[0]);
	return (process);
}
