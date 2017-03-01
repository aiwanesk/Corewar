#include "test.h"

static void test_overflow(){
	t_process p = create_process();

	p.pc = 100;
	p.memory[100] = 3;
	p.memory[101] = 80;
	p.memory[102] = 2 + 16;
	p.memory[103] = 3 + 16;
	p.reg[2] = 12;
	p.reg[3] = 12;
	p.reg[12] = 99;
	p = cpu(p);
	if (p.memory[100 + (12 % IDX_MOD)] == 99)
		printf("%stest_overflow ok\n", CGREEN);
	else
		printf("%stest_overflow bug\n", CRED);
	printf("%s", CWHITE);
}

static void test_simple(){
	t_process p = create_process();

	p.pc = 100;
	p.memory[100] = 3;
	p.memory[101] = 80;
	p.memory[102] = 2;
	p.memory[103] = 3;
	p.reg[2] = 12;
	p.reg[3] = 12;
	p.reg[12] = 99;
	p = cpu(p);
	if (p.memory[100 + (12 % IDX_MOD)] == 99)
		printf("%stest_simple ok\n", CGREEN);
	else
		printf("%stest_simple bug\n", CRED);
	printf("%s", CWHITE);
}

void test_st(){
	test_simple();
	test_overflow();
}
