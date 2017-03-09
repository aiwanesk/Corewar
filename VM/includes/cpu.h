/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:52:48 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/08 16:23:21 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

# include "core.h"
# include "libft.h"

# include <stdint.h>
# include <stdbool.h>

# define PCANDARG (process->pc + 2)
# define CGREEN "\033[32m"
# define CRED "\033[31m"
# define CWHITE  "\033[37m"

typedef struct s_data		t_data;
typedef struct s_arg		t_arg;
typedef struct s_fork		t_fork;

struct				s_data
{
	char val[9];
};

struct				s_arg
{
	int total_to_read[4];
};

t_arg				parsing_request(t_process *p,
		unsigned char memory[MEM_SIZE]);

struct s_data		get_data_from_hex(int val);
int					int_to_bin(unsigned int k);

void				exit_error(char *s);

void				apply_function(t_process *process);

void				apply_and(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_or(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_xor(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);

void				apply_add(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_sub(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);

void				apply_ld(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_st(t_process *process, t_arg arg, t_env *env);

void				apply_aff(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_fork(t_process *process, t_env *env,
t_arg arg);
void				apply_lfork(t_process *process, t_env *env,
t_arg arg);

void				apply_ldi(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_sti(t_process *process, t_arg arg, t_env *env);
void				apply_lld(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_lldi(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);

void				apply_live(t_process *process,
		unsigned char memory[MEM_SIZE], t_env *env);
void				apply_zjmp(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);

int					int_to_read(char *t, int i, int op);
void			assign(uint32_t val, uint32_t **bit);

#endif
