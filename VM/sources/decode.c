#include "cpu.h"

void		decode(t_args args[3], uint32_t pc, unsigned char encoding)
{
	int			i;
	int			a;
	int			elem;

	a = MAX_ARGS;
	while (a > 0)
	{
		i = a - 1;
		elem = MAX_ARGS - a;
		args[elem].arg = (encoding >> (2 * (i + 1))) & 0x3;
		if (args[elem].arg == T_DIR)
			args[elem].length = length_label(pc);
		else
			args[elem].length = args[elem].arg;
		--a;
	}
}
