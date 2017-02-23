#ifndef PARSING_REQUEST_H
# define PARSING_REQUEST_H

#include "../libs/libft/include/libft.h"
#include "../includes/op.h"

typedef struct				s_data t_data;
typedef struct				s_process t_process;
typedef struct				s_arg t_arg;

struct s_dict		g_tab[2];

struct						s_process{
	uint32_t				pc;
	int						cycle;
};

struct						s_data{
	char					val[8];
};

struct						s_arg{
	int						total_to_read[4];
};


int				parse_request(t_process *p, char memory[MEM_SIZE]);

struct s_data	get_data_from_hex(int val);
unsigned int	int_to_bin(unsigned int k);

int				which_registre(char *bit);

void			exit_error(char *s);

t_process		cpu(t_process p, char memory[MEM_SIZE]);

#endif
