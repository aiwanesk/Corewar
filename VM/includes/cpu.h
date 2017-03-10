/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:52:48 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/10 10:38:15 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

# include "core.h"
# include "op.h"
# include "libft.h"

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>

# define BYPASS_ARG_ENCODE 2
# define BYPASS_ARG 1
# define BYPASS(X, BYPASS) (X[0].length + X[1].length + X[2].length + BYPASS)
# define CGREEN "\033[32m"
# define CRED "\033[31m"
# define CWHITE  "\033[37m"

# define MAX_ARGS	3

typedef struct s_data		t_data;
typedef struct s_fork		t_fork;

typedef enum e_value		t_value;
typedef struct s_args		t_args;

typedef struct s_op			t_op;
typedef void (*t_fct_cpu) (t_process *process, t_env *env);

enum						e_value
{
	reg = T_REG,
	dir = T_DIR,
	ind = T_IND
};

struct						s_args
{
	t_value			arg;
	unsigned int	length;
};

struct						s_op
{
	uint32_t		opcode;
	int				length;
};

void				exit_error(char *s);

void				apply_function(t_process *process);

void				apply_and(t_process *process, t_env *env);
void				apply_or(t_process *process, t_env *env);
void				apply_xor(t_process *process, t_env *env);

void				apply_add(t_process *process, t_env *env);
void				apply_sub(t_process *process, t_env *env);

void				apply_ld(t_process *process, t_env *env);
void				apply_st(t_process *process, t_env *env);

void				apply_aff(t_process *process, t_env *env);
void				apply_fork(t_process *process, t_env *env);
void				apply_lfork(t_process *process, t_env *env);

void				apply_ldi(t_process *process, t_env *env);
void				apply_sti(t_process *process, t_env *env);
void				apply_lld(t_process *process, t_env *env);
void				apply_lldi(t_process *process, t_env *env);

void				apply_live(t_process *process, t_env *env);
void				apply_zjmp(t_process *process, t_env *env);

/*
** Tools 
*/

int					int_to_read(char *t, int i, int op); //TO DEL PERHAPS?
void				decode(t_args *args, uint32_t pc, unsigned char encoding);
int					length_label(uint32_t opcode);
uint32_t			get_args(unsigned char *memory, uint32_t addr, int oct);
uint32_t			return_value(t_process *p, unsigned char *me,
												t_args arg, uint32_t val);
void				assign(uint32_t val, uint32_t **bit); //TO DEL PERHAPS?

#endif
