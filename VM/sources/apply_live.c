/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:09:42 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/06 17:48:32 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

void				apply_live(t_process *process,
		unsigned char memory[MEM_SIZE], t_env *env)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < 4)
	{
		total += memory[process->pc + i];
		i++;
	}
	printf("Live Called id[%u]\n", process->id);
	process->pc = (process->pc + i + 1) % MEM_SIZE;
	process->nb_cycle -= 10;
	//TODO c'est ca que tu veux?
	i = 0;
	while (i < 255)
	{
		if (i == total)
		{
			env->process[i].alive++;
			break;
		}
		i++;
	}
}
