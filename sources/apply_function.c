#include "cpu.h"

void				apply_function(t_process **process)
{
	if ((*process)->pc == 1)
		apply_live(process);
}
