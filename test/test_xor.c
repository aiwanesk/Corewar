#include "test.h"

/*
void db(t_process p){
	int i = 0;
	for (; i < 16; i++)
		printf("%d\n", p.reg[i]);
}*/

static void test_overflow_memory(){
	t_process p = create_process();
	p.pc = MEM_SIZE - 1;
	int j = 0;
	for (; j < MEM_SIZE; j++)
		p.memory[j] = 120;
	p.memory[MEM_SIZE - 1] =  8;
	p.nb_cycle = 100;
	p = cpu(p);
	if (p.reg[0] == 136)
		printf("%stest_overflow_memory ok!\n", CGREEN);
	else
		printf("%stest_overflow_memory bug!\n", CRED);
	printf("%s", CWHITE);
}

static void test_std_cmp(){
	t_process p = create_process();
	p.pc = 120;
	int j = 0;
	for (; j < MEM_SIZE; j++)
		p.memory[j] = 120;
	p.memory[120] =  8;
	p.nb_cycle = 100;
	p = cpu(p);
	if (p.reg[0] == 136)
		printf("%stest_std_memory ok!\n", CGREEN);
	else
		printf("%stest_std_memory bug!\n", CRED);
	printf("%s", CWHITE);
}

static void test_facile(){
	t_process p = create_process();
	p.pc = 120;
	int j = 0;
	for (; j < MEM_SIZE; j++)
		p.memory[j] = 84;
	p.memory[120] =  8;
	p.nb_cycle = 100;
	p = cpu(p);
	if (p.reg[4] == 0)
		printf("%stest_facile_memory ok!\n", CGREEN);
	else
		printf("%stest_facile_memory bug!\n", CRED);
	printf("%s", CWHITE);
}

void test_xor(){
	test_std_cmp();
	test_overflow_memory();
	test_facile();
}
