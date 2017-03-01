#include "test.h"

t_process		create_process(){
	t_process ret;
	int i;

	for (i = 0; i < 16; i++)
		ret.reg[i] = 0;
	ret.pc = 0;
	ret.id = 0;
	ret.alive = 1;
	ret.carry = 0;
	ret.name = strdup("salut");
	ret.nb_cycle = 1900;
	for (i = 0; i < MEM_SIZE; i++){
		ret.memory[i] =  i % MEM_SIZE;
//		printf("%d", ret.memory[i]);
//		if (i + 1 % 100 == 0)
//			printf("\n");
	}
	return ret;
}
