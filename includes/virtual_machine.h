/*
 * ****************
** HEADER MBA
** ****************
*/

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# include <unistd.h>

# ifndef STDERR
#  define STDERR STDERR_FILENO
# endif

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
	char			memory[MEM_SIZE];
	unsigned char	carry;
};

struct					s_env
{
};

void					virtual_machine(t_env env);
t_options				parse_options(const char **data, t_options opt);

void					write_memory(char memory[MEM_SIZE], uint32_t addr, uint32_t val);
uint32_t				read_memory(char memory[MEM_SIZE], uint32_t addr);
char					*cpy_memory(char memory[MEM_SIZE], char cpy[MEM_SIZE]);

t_process				cpu(t_process process);

# endif
