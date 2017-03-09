/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:05:51 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:02:48 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c.
** Crée un nouveau processus, qui hérite des différents états de son père,
** à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

void						apply_fork(t_process *p, t_env *env, t_arg arg)
{
	int			i;
	uint32_t	f;

	printf("Instruction fork\n");
	i = 0;
	f = 0;
	while (i < arg.total_to_read[0])
	{
		f<<= 8;
		f |= env->memory[p->pc + 1 + i];
		i++;
	}
	p->fork.pc = p->pc + (f % IDX_MOD);
	p->pc = (p->pc + i + 2) % MEM_SIZE;
	p->nb_cycle -= 800;
}
