#include "test.h"

static void test_one_two_three(){
	t_process p = create_process();

	p.pc = 1;
	p.memory[1] = 5;
	p.memory[2] = 84;
	p.memory[3] = 0;
	p.memory[4] = 1;
	p.memory[5] = 2;
	p.reg[0] = 12;
	p.reg[1] = 24;

	p = cpu(p);
	if (p.reg[2] == -12)
		printf("%stest_1_2_3 ok !\n", CGREEN);
	else
		printf("%stest_1_2_3 bug !\n", CRED);
	printf("%s", CWHITE);
}

static void test_overflow(){
	t_process p = create_process();

	p.pc = MEM_SIZE - 1;
	p.memory[MEM_SIZE - 1] = 5;
	p.memory[0] = 84;
	p.memory[1] = 0;
	p.memory[2] = 1;
	p.memory[3] = 2;
	p.reg[0] = 99;
	p.reg[1] = 100;

	p = cpu(p);
	if (p.reg[2] == -1)
		printf("%stest_overflow ok !\n", CGREEN);
	else
		printf("%stest_overflow bug !\n", CRED);
	printf("%s", CWHITE);
}

static void test_overflow_registre(){
	t_process p = create_process();

	p.pc = MEM_SIZE - 1;
	p.memory[MEM_SIZE - 1] = 5;
	p.memory[0] = 84;
	p.memory[1] = 14;
	p.memory[2] = 15;
	p.memory[3] = 66;
	p.reg[14] = 99;
	p.reg[15] = 12;

	p = cpu(p);
	int i = 0;
	if (p.reg[2] == 99 - 12)
		printf("%stest_overflow_registre ok !\n", CGREEN);
	else
		printf("%stest_overflow_registre bug !\n", CRED);
	printf("%s", CWHITE);
}

void test_sub(){
	test_one_two_three();
	test_overflow();
	test_overflow_registre();
}
