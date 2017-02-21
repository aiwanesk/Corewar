#ifndef CPU_H
# define CPU_H

# include "../libs/libft/include/libft.h"
# include "op.h"

#include <stdio.h> //for debug purpose only
#define CGREEN "\033[32m"
#define CRED "\033[31m"
#define CWHITE  "\033[37m"

typedef struct		s_process{
	uint32_t		reg[16];
	uint32_t		pc;
	uint32_t		id;
	uint32_t		alive;
	unsigned char	carry;
	char			*name;
	uint32_t		nb_cycle;
	char			memory[MEM_SIZE];
}					t_process;

t_process			cpu(t_process process);

void				apply_function(t_process *process);

void				apply_live(t_process *process);
void				apply_ld(t_process *process, uint32_t value, int registre);
void				apply_and(t_process *process, uint32_t v1, uint32_t v2, int addr);
void				apply_or(t_process *process, uint32_t v1, uint32_t v2, int addr);
void				apply_xor(t_process *process, uint32_t v1, uint32_t v2, int addr);

//TODO this test
void				apply_add(t_process *process, uint32_t v1, uint32_t v2, int addr);
void				apply_sub(t_process *process, uint32_t v1, uint32_t v2, int addr);
void				apply_st(t_process *process, int source, int addr);
void				apply_zjmp(t_process *process, uint32_t dest);

#endif
