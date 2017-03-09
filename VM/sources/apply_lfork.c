/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:08:23 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:06:02 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c.
**Crée un nouveau processus, qui hrite des diffrents états de son pre,à part
** son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

void						apply_lfork(t_process *p, t_env *env, t_arg arg)
{
	int			i;
	uint32_t	f;

	printf("Instruction lfork\n");
	i = 0;
	f = 0;
	while (i < arg.total_to_read[0])
	{
		f<<=8;
		f |= env->memory[p->pc + 1 + i];
		i++;
	}
	p->fork.pc = p->pc + (f);
	p->pc = (p->pc + i + 2) % MEM_SIZE;
	p->nb_cycle -= 1000;
}
