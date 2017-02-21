#include "test.h"
#include <limits.h>

static void		fill_process(struct s_process *p, int carry, int valRegistre){
	int i;

	for (i = 0; i < 16; i++)
		p->reg[i] = valRegistre;
	p->carry = carry;
}

static void		test_ld_ok(struct s_process *p){
	apply_ld(p, 130, 1);

	if (p->reg[1] == 130 && p->carry == 1)
		printf("%stest_ld_ok OK!\n", CGREEN);
	else
		printf("%stest_ld_ok BUG!\n", CRED);
}

static void		test_ld_overflow(struct s_process *p){
	apply_ld(p, INT_MAX + 1, 14);

	//if no crash ok?
	//TODO uint32_t  < 0???
	if (p->reg[14] == 130 && p->carry == 1)
		printf("%stest_ld_overflow OK!\n", CGREEN);
	else
		printf("%stest_ld_overflowk BUG!\n", CRED);
}

static void		test_ld_underflow(struct s_process *p){
	apply_ld(p, INT_MIN - 1, 12);

	//if no crash ok?
	//TODO uint32_t  < 0???
	if (p->reg[14] == 130 && p->carry == 1)
		printf("%stest_ld_overflow OK!\n", CGREEN);
	else
		printf("%stest_ld_overflowk BUG!\n", CRED);
}

static void		test_invalid_registre(struct s_process *p, int val){
	apply_ld(p, 14, val);
}

//TODO think more about this test

void			launcher_test_ld(){
	struct s_process p;

	fill_process(&p, 0, 122);
	test_ld_ok(&p);
	fill_process(&p, 0, 122);
	test_ld_overflow(&p);
	fill_process(&p, 0, 122);
	test_ld_underflow(&p);
	fill_process(&p, 0, 122);
	test_invalid_registre(&p, -1);
	fill_process(&p, 0, 122);
	test_invalid_registre(&p, 46);
}
