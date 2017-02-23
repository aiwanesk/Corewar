#ifndef PARSING_REQUEST_H
# define PARSING_REQUEST_H

//#include "../libs/libft/include/libft.h"

#include "op_dict.h"

#include <stdint.h>
#include <stdio.h>//TODO REMOVE FOR CORRECTION
#include <stdlib.h>

typedef struct s_process	t_process;

#define MEM_SIZE 4096

struct				s_process
{
	uint32_t		reg[16];
	uint32_t		pc;
	uint32_t		id;
	uint32_t		alive;
	uint32_t		nb_cycle;
	char*			name;
	uint32_t		memory[MEM_SIZE];
	unsigned char	carry;
};


t_process		cpu(t_process process, char memory[MEM_SIZE]);
void			parse_request(uint32_t pc_position, char memory[MEM_SIZE]);

void			exit_error(char *s);

#endif
