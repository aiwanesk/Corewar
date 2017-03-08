/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:13:03 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:03:48 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** st : Prend un registre et un registre ou un indirect, et stocke la valeur du
** vers le second paramètre. Son opcode est 0x03. Par exemple, st r1, 42 stocke
** valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
*/

void				apply_st(t_process *process, struct s_arg arg, t_env *env)
{
	int		i;
	int		reg;
	int		second;

		printf("Instruction st\n");
	i = -1;
	reg = 0;
	while (++i < arg.total_to_read[0])
		reg += env->memory[(PCANDARG + i) % MEM_SIZE];
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += env->memory[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	if (arg.total_to_read[0] == 1)
		reg = process->reg[(reg - 1) % REG_NUMBER];
	if (arg.total_to_read[1] == 1)
		second = process->reg[(second - 1 ) % REG_NUMBER];
	env->memory[(process->pc + (second % IDX_MOD)) % MEM_SIZE] =
		process->reg[reg % REG_NUMBER];
	process->pc = (process->pc + i + 2) % MEM_SIZE;
	protocol_pc(*env, *process, process->pc);
	process->nb_cycle = 5;
}
