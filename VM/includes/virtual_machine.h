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
	int				dumpcycle;
	unsigned int	nbchampions;
	char			*champions[MAX_PLAYERS];
	int				error;
};

struct					s_process
{
	uint32_t		id;
	uint32_t		pc;
	uint32_t		reg[16];
	uint32_t		alive;
	uint32_t		nb_cycle;
	char			name[PROG_NAME_LENGTH + 1];
	unsigned char	carry;
	char			*memory;
};

struct					s_env
{
	uint32_t		memory[MEM_SIZE];
	_Bool			isdump;
	unsigned int	cycle_total;
	t_process		process[255];
	int				error;
	char			*s_error;
};

int						virtual_machine(t_env env);
t_env					init_virtual_machine(t_options opt);
t_options				parse_options(char **data, t_options opt);

void					write_memory(uint32_t *memory, uint32_t addr, uint32_t val);
uint32_t				read_memory(uint32_t *memory, uint32_t addr);
void					cpy_memory(uint32_t *memory, uint32_t *cpy);
void					print_memory(uint32_t *memory);

t_process				cpu(t_process process);

uint32_t				random_uint32(void);
void					check_random(t_process process[], int n);
t_env					load_champion(t_env env, t_options opt, int id);
t_process				new_process(t_options opt, int id);
t_env					create_process(t_env env, t_options opt);
int						process_alive(t_env env);

# endif
