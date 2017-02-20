#include "cpu.h"

int				main(){
	t_process			*p;

	p = (t_process *)malloc(sizeof(t_process));
	apply_function(&p);
	return (0);
}
