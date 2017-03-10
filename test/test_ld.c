#include "test.h"

static void test_overflow(){
	t_process p = create_process();

	p.pc = 100;
	p.memory[100] = 2;
	p.memory[101] = 208;
	p.memory[102] = 0;
	p.memory[103] = 100;
	p.memory[104] = 3 + 16;
	p.reg[3] = 12;
	p = cpu(p);
	if (p.memory[100 + (208 % IDX_MOD)] == 52)
		printf("%stest_overflow ok\n", CGREEN);
	else
		printf("%stest_overflow bug\n", CRED);
	printf("%s", CWHITE);
}

static void test_simple(){
	t_process p = create_process();

	p.pc = 100;
	p.memory[100] = 2;
	p.memory[101] = 208;
	p.memory[102] = 0;
	p.memory[103] = 100;
	p.memory[104] = 3;
	p.reg[3] = 12;
	p = cpu(p);
	if (p.memory[100 + (208 % IDX_MOD)] == 52)
		printf("%stest_simple ok\n", CGREEN);
	else
		printf("%stest_simple bug\n", CRED);
	printf("%s", CWHITE);
}

void test_ld(){
	test_simple();
	test_overflow();
}
