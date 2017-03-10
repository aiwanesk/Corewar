/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:06:24 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 12:45:46 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

void			apply_ld(t_process *process, t_env *env)
{
	printf("Instruction ld\n");
	(void)env;
	return ;
	process->carry = 1;
	process->pc = (process->pc + 1 + 2) % MEM_SIZE;
	process->nb_cycle -= 5;
}
