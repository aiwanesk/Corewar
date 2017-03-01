#include "test.h"

void test_or(){
	t_process p = create_process();

	p.pc = 100;
	p.memory[100] = 7;
	p.memory[101] = 120;
	p.memory[102] = 10;
	p.memory[103] = 150;
	p.memory[104] = 150;
	p.memory[105] = 150;
	p.memory[106] = 10;
	p.memory[107] = 10;
	p.nb_cycle = 1000;
	p = cpu(p);
	//p.memory[100] = 6;
	//p = cpu(p);
	int i = 0;
	for (; i < 16; i++)
		printf("%d\n", p.reg[i]);
}
