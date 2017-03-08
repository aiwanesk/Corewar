/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:09:42 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/08 16:44:33 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

void				apply_live(t_process *process,
		unsigned char memory[MEM_SIZE], t_env *env)
{
//	int		i;
	int		total;
	(void )env;
	printf("Instruction live\n");
	total = (unsigned int)memory[process->pc + 1];
	process->pc += (sizeof(unsigned int) + 1 % MEM_SIZE);
	process->nb_cycle -= 10;
	++env->process[total].alive;
}
