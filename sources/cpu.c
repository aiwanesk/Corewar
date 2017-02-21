#include "cpu.h"

t_process				cpu(t_process process)
{
	if (process.pc == 1)
		apply_live(&process);
//	else if (process.pc == 2)
//		apply_ld(&process);
	return (process);
}
