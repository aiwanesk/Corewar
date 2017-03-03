/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:04:19 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/03 15:04:24 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cpu.h"

void					apply_aff(t_process *p,
		unsigned char mem[MEM_SIZE], t_arg arg)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (i < arg.total_to_read[0])
	{
		f += mem[p->pc + 1 + i];
		i++;
	}
	ft_putnbr(p->reg[f] % 127);
}