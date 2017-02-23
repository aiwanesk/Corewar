#include "test.h"
#include <limits.h>

static void fill_test(t_process *p, uint32_t v1, uint32_t v2){
	p->reg[0] = v1;
	p->reg[1] = v2;
	p->reg[2] = 0;
}

static void test_or_basic(t_process *p){
	apply_or(p, p->reg[0], p->reg[1], 2);

	if (p->reg[2] == 28)
		logWriter("test_or_basic ok!", SUCCESS);
	else
		logWriter("test_or_basic bug!", FAILURE);
}

static void test_or_basic_2(t_process *p){
	apply_or(p, p->reg[0], p->reg[1], 2);

	if (p->reg[2] == 48)
		logWriter("test_or_basic_2 ok!", SUCCESS);
	else
		logWriter("test_or_basic_2 bug!", FAILURE);
}

static void test_or_overflow(t_process *p){
	apply_or(p, p->reg[0], p->reg[1], 2);

	if (p->reg[2] == INT_MAX)
		logWriter("test_or_overflow ok!", SUCCESS);
	else
		logWriter("test_or_overflow bug!", FAILURE);
}

static void test_or_underflow(t_process *p){
	apply_or(p, p->reg[0], p->reg[1], 2);

	if (p->reg[2] == 4294967295)
		logWriter("test_or_underflow ok!", SUCCESS);
	else
		logWriter("test_or_underflow bug!", FAILURE);
}

void launcher_test_or(){
	t_process p;

	fill_test(&p, 12,24);
	test_or_basic(&p);
	fill_test(&p, INT_MAX, 123);
	test_or_overflow(&p);
	fill_test(&p, 16, 32);
	test_or_basic_2(&p);
	fill_test(&p, INT_MIN, INT_MAX);
	test_or_underflow(&p);
}
