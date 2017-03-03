/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:09:42 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/03 16:36:47 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

void				apply_live(t_process *process,
		unsigned char memory[MEM_SIZE])
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
	//=TODO comment suis je sense savoir comment se portent les autres process sans requetE?
}
