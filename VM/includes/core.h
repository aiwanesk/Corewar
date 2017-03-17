/*
 * ****************
** HEADER MBA
** ****************
*/

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# include <unistd.h>
# include <stdint.h>
#include "op.h"

# ifndef STDERR
#  define STDERR STDERR_FILENO
# endif

# define BASE_16 "0123456789ABCDEF" //TODO del it if not use !

typedef struct s_options	t_options;
typedef struct s_process	t_process;
typedef struct s_env		t_env;
typedef struct s_fork		t_fork;

# define MATCH_NULL (t_process) {.id = 0 }

# define PAGE_PROC 255

struct					s_fork
{
	_Bool			isfork;
	uint32_t		pc;
};

struct					s_options
{
	int				dumpcycle;
	unsigned int	nbchampions;
	char			*champions[MAX_PLAYERS + 1];
	int				id[MAX_PLAYERS + 1];
	_Bool			ui;
	int				error;
};

struct					s_process
{
	uint32_t		id;
	int16_t			pc;
	uint32_t		reg[16];
	uint32_t		alive;
	uint32_t		nb_cycle;
	char			name[PROG_NAME_LENGTH + 1];
	unsigned char	carry;
	_Bool			isdead;
	t_fork			fork;
};

struct					s_env
{
	unsigned char	memory[MEM_SIZE];
	int				idlive[MAX_PLAYERS];
	int				live[MAX_PLAYERS];
	uint32_t		dump;
	unsigned int	cycle_to_die;
	unsigned int	cycles;
	unsigned int	nbprocess;
	unsigned int	maxprocess;
	t_process		*process;
	_Bool			error;
	char			*s_error;
	_Bool			run;
	uint32_t		nblive;
	uint32_t		check;
	_Bool			ui;
};

struct				s_test
{
	int toto;
};

/*
** core.c file
** VM CORE
*/
void					core(t_env env);
t_env					init_core(t_options opt);
int						winner(t_env env, t_process process);

/*
** set_options.c file
** function handle options of call executable
** #1 -dump `X` --> generate `X` before print memory and close VM
** #2 -n `X` file.cor --> insert into VM `X` champions
*/
t_options				parse_options(char **data, t_options opt);
int						error_options(t_options opt);

/*
** memory.c file
** function handle memory
*/
void					write_memory(unsigned char *memory, uint32_t addr, uint32_t val);
void					print_memory(unsigned char *memory, t_env env);
uint32_t				read_memory(unsigned char *memory, uint32_t addr);
void					print_hex(uintmax_t hex, char *base);

//TODO LUI PASSSER UN T ENV
void				cpu(t_process *process, t_env *env);


/*
** random.c file
** function that generate or control random uint32_t for all process
*/
uint32_t				random_uint32(void);
void					check_random(t_process process[], int n);

/*
** tools.c file
** function that load champion in memory (why dont move this in memory file???
** and convert endianness to transform big endian PROG_SIZE and Magic NUMBER 
** to little endian
*/
uint32_t				convert_endianness(unsigned int val);
t_env					load_champion(t_env env, t_options opt, int id);
void					ft_putnbr_uint32(uint32_t i);

/*
** process.c file
*/
t_process				new_process(t_options opt, int id);
t_env					create_process(t_env env, t_options opt);
int						process_alive(t_env env);
t_process				get_process_by_id(t_env env, uint32_t id);

/*
** map.c file
*/
t_env					process_map(t_env env, t_env (*fct)(t_env env, int i));
t_env					add_cycle(t_env env, int i);
t_env					check_live(t_env env);
t_env					execute_cpu(t_env env, int i);
t_env					create_fork(t_env env, int i);

/*
** protocol_ui.c file
*/
void					protocol_lmz(t_env e, int id, uint32_t len,	char *str);
void					protocol_pc(t_env env, t_process pro, uint32_t addr);
void					protocol_win(t_env env, t_process process);
void					protocol_lc(t_env env);
void					protocol_mem(t_env env, t_process proc, uint32_t addr);
void					protocol_sleep(t_env env);

# endif
