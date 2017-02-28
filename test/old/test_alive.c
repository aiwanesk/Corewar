#include "test.h"

static void		fill_process(struct s_process *p, int pc, int live){
	p->name = ft_strdup("pandaContent");
	p->pc = pc;
	p->alive = live;
}

static void		test_alive_ok(struct s_process *p){
	char	toCompare[1000];
	char	std[1000];

	setbuf(stdout, std);
	setbuf(stderr, toCompare);
	apply_live(p);
	if (ft_strcmp(toCompare, "un processus est en vie") == 0)
		logWriter("test_alive_ok", SUCCESS);
	else
		logWriter("test_alive_ok", FAILURE);
}

static void		test_alive_not_ok(struct s_process *p){
	char	toCompare[1000];
	char	std[1000];

	setbuf(stdout, std);
	setbuf(stderr, toCompare);
	apply_live(p);
	if (ft_strcmp(toCompare, "un processus est mort") == 0)
		logWriter("test_alive_notnot__ok", SUCCESS);
	else
		logWriter("test_alive_not_ok", FAILURE);
}

void			launcher_test_alive(){
	struct s_process p;

	fill_process(&p, 1, 1);
	test_alive_ok(&p);
	fill_process(&p, 1, 0);
	test_alive_not_ok(&p);
}
