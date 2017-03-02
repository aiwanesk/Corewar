#include "cpu.h"

int			int_to_bin(unsigned int k)
{
	return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bin(k / 2)));
}
