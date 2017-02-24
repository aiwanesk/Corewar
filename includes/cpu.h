#ifndef CPU_H
# define CPU_H

# include "../libs/libft/include/libft.h"
# include "op.h"

#include <stdint.h>
#include <stdio.h> //for debug purpose only
#define CGREEN "\033[32m"
#define CRED "\033[31m"
#define CWHITE  "\033[37m"

typedef struct s_data t_data;
typedef struct s_process t_process;
typedef struct s_arg t_arg;

struct s_dict g_tab[2];

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


struct	s_data{
	char val[8];
};

struct s_arg{
	int total_to_read[4];
};

struct s_arg parsing_request(t_process *p, char memory[MEM_SIZE]);

struct s_data get_data_from_hex(int val);
unsigned int int_to_bin(unsigned int k);

void exit_error(char *s);

t_process cpu(t_process p, char memory[MEM_SIZE]);

#define PCANDARG (process->pc + 2)

void				apply_function(t_process *process);

//TODO this test
void				apply_live(t_process *process, char memory[MEM_SIZE]);
void				apply_ld(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_st(t_process *process, char *memory[MEM_SIZE], t_arg arg);
void				apply_add(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_sub(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_and(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_or(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_xor(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_zjmp(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_ldi(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_sti(t_process *process, char *memory[MEM_SIZE], t_arg arg);
void				apply_fork(t_process *process, char *memory[MEM_SIZE], t_arg arg);
void				apply_lld(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_lldi(t_process *process, char memory[MEM_SIZE], t_arg arg);
void				apply_lfork(t_process *process, char *memory[MEM_SIZE], t_arg arg);
void				apply_aff(t_process *process, char memory[MEM_SIZE], t_arg arg);

#endif
