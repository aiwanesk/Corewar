/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:01:48 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 16:06:22 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <unistd.h>
# include <stdint.h>
# include "op.h"

# ifndef STDERR
#  define STDERR STDERR_FILENO
# endif

# define BASE_16 "0123456789abcdef"

typedef struct s_options			t_options;
typedef struct s_process			t_process;
typedef struct s_env				t_env;
typedef struct s_fork				t_fork;

# define MATCH_NULL (t_process) {.id = 0 }

# define PAGE_PROC 255

struct								s_fork
{
	_Bool							isfork;
	int32_t						pc;
};

struct								s_options
{
	int								dumpcycle;
	int32_t					nbchampions;
	char							*champions[MAX_PLAYERS + 1];
	int								id[MAX_PLAYERS + 1];
	_Bool							ui;
	int								error;
};

struct								s_process
{
	int32_t							id;
	int16_t							pc;
	int32_t						reg[15];
	int32_t						alive;
	int32_t						nb_cycle;
	char							name[PROG_NAME_LENGTH + 1];
	unsigned char					carry;
	_Bool							isdead;
	t_fork							fork;
};

struct								s_env
{
	unsigned char					memory[MEM_SIZE];
	int								idlive[MAX_PLAYERS];
	int								live[MAX_PLAYERS];
	int32_t							dump;
	unsigned int					cycle_to_die;
	unsigned int					cycles;
	unsigned int					nbprocess;
	unsigned int					maxprocess;
	t_process						*process;
	_Bool							error;
	char							*s_error;
	_Bool							run;
	int32_t						nblive;
	int32_t						check;
	_Bool							ui;
};

/*
** core.c file
** VM CORE
*/
void								core(t_env env);
t_env								init_core(t_options opt);
int									winner(t_env env, t_process process);
t_env								check_live(t_env env);

/*
** set_options.c file
** function handle options of call executable
** #1 -dump `X` --> generate `X` before print memory and close VM
** #2 -n `X` file.cor --> insert into VM `X` champions
*/
t_options							parse_options(char **data, t_options opt);
int									error_options(t_options opt);

/*
** memory.c file
** function handle memory
*/
void								write_memory(unsigned char *memory,
		int32_t addr, int32_t val);
void								print_memory(unsigned char *memory,
		t_env env);
int32_t							read_memory(unsigned char *memory,
		int32_t addr);
void								print_hex(uintmax_t hex, char *base);

void								cpu(t_process *process, t_env *env);

/*
** random.c file
** function that generate or control random int32_t for all process
*/
int32_t							random_uint32(void);
void								check_random(t_process process[], int n);

/*
** tools.c file
** function that load champion in memory (why dont move this in memory file???
** and convert endianness to transform big endian PROG_SIZE and Magic NUMBER
** to little endian
*/
int32_t							convert_endianness(unsigned int val);
t_env								load_champion(t_env env, t_options opt,
		int id);
void								ft_putnbr_uint32(int32_t i);

/*
** process.c file
*/
t_process							new_process(t_options opt, int id);
t_env								create_process(t_env env, t_options opt);
int									process_alive(t_env env);
t_process							get_process_by_id(t_env env, int32_t id);

/*
** map.c file
*/
t_env								process_map(t_env env,
		t_env (*fct)(t_env env, int i));
t_env								add_cycle(t_env env, int i);
t_env								process_live(t_env env, int i);
t_env								execute_cpu(t_env env, int i);
t_env								create_fork(t_env env, int i);

/*
** protocol_ui.c file
*/
void								protocol_lmz(t_env e, int id, int32_t len,
		char *str);
void								protocol_pc(t_env env, t_process pro,
		int32_t addr);
void								protocol_win(t_env env, t_process process);
void								protocol_lc(t_env env);
void								protocol_mem(t_env env, t_process proc,
		int32_t addr);
void								protocol_sleep(t_env env);

void								norme_live(t_env *env);

#endif
