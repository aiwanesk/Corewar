/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:13:03 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/03 18:27:31 by aiwanesk         ###   ########.fr       */
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

	i = -1;
	reg = 0;
	while (++i < arg.total_to_read[0])
		reg += process->memory[(PCANDARG + i) % MEM_SIZE];
	second = 0;
	while (i < arg.total_to_read[0] + arg.total_to_read[1])
	{
		second += process->memory[(PCANDARG + i) % MEM_SIZE];
		i++;
	}
	if (arg.total_to_read[0] == 1)
		reg = process->reg[reg % REG_NUMBER];
	if (arg.total_to_read[1] == 1)
		second = process->reg[second % REG_NUMBER];
	process->memory[(process->pc + (second % IDX_MOD)) % MEM_SIZE] =
		process->reg[reg % REG_NUMBER];
	//TODO application du protocol
	(void)env;
}
