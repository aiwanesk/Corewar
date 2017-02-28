#include "test.h"

void test_or(){
	t_process p = create_process();

	p.pc = 100;
	p.memory[100] = 7;
	p.nb_cycle = 1000;
	p = cpu(p);
	printf("%d %d\n", p.reg[0], p.reg[1]);
}
