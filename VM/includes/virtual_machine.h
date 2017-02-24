/*
 * ****************
** HEADER MBA
** ****************
*/

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# include <unistd.h>
# include <stdint.h>
# include "op.h"

# ifndef STDERR
#  define STDERR STDERR_FILENO
# endif

# define BASE_16 "0123456789ABCDEF" //TODO del it if not use !

typedef struct s_options	t_options;
typedef struct s_process	t_process;
typedef struct s_env		t_env;

struct					s_options
{
	int		nbcycle;
	int		nbchampions;
	char	*champions[255];
	int		error;
};

struct					s_process
{
	uint32_t		reg[16];
	uint32_t		pc;
	uint32_t		id;
	uint32_t		alive;
	uint32_t		nb_cycle;
	char			*name;
	uint32_t		memory[MEM_SIZE];
	unsigned char	carry;
};

struct					s_env
{
	uint32_t		virtual_memory[MEM_SIZE];
	unsigned int	cycle_total;
};

void					virtual_machine(t_env env);
t_options				parse_options(char **data, t_options opt);

void					write_memory(uint32_t *memory, uint32_t addr, uint32_t val);
uint32_t				read_memory(uint32_t *memory, uint32_t addr);
void					cpy_memory(uint32_t *memory, uint32_t *cpy);
void					print_memory(uint32_t *memory);

t_process				cpu(t_process process);

# endif
