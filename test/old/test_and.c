#include "test.h"
#include <limits.h>

static void fill_test(t_process *p, uint32_t v1, uint32_t v2){
	p->reg[0] = v1;
	p->reg[1] = v2;
	p->reg[2] = 0;
}

static void test_and_basic(t_process *p){
	apply_and(p, p->reg[0], p->reg[1], 2);

	if (p->reg[2] == 8)
		logWriter("test_and_basic ok!", SUCCESS);
	else
		logWriter("test_and_basic bug!", FAILURE);
}

static void test_and_basic_2(t_process *p){
	apply_and(p, p->reg[0], p->reg[1], 2);

	if (p->reg[2] == 0)
		logWriter("test_and_basic_2 ok!", SUCCESS);
	else
		logWriter("test_and_basic_2 bug!", FAILURE);
}

static void test_and_overflow(t_process *p){
	apply_and(p, p->reg[0], p->reg[1], 2);

	if (p->reg[2] == 123)
		logWriter("test_and_overflow ok!", SUCCESS);
	else
		logWriter("test_and_overflow bug!", FAILURE);
}

static void test_and_underflow(t_process *p){
	apply_and(p, p->reg[0], p->reg[1], 2);

	if (p->reg[2] == 0)
		logWriter("test_and_underflow ok!", SUCCESS);
	else
		logWriter("test_and_underflow bug!", FAILURE);
}

void launcher_test_and(){
	t_process p;

	fill_test(&p, 12,24);
	test_and_basic(&p);
	fill_test(&p, INT_MAX, 123);
	test_and_overflow(&p);
	fill_test(&p, 16, 32);
	test_and_basic_2(&p);
	fill_test(&p, INT_MIN, INT_MAX);
	test_and_underflow(&p);
}
