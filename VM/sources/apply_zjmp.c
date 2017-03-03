/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:18:38 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/03 16:38:24 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
**zjmp : Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage des
**paramètres derrière cette opération dont l’opcode est de 9. Elle prendra un in
*/

void					apply_zjmp(t_process *p,
		unsigned char mem[MEM_SIZE], t_arg arg)
{
	int			i;
	uint32_t	dest;

	i = 0;
	dest = 0;
	while (i < arg.total_to_read[0])
	{
		dest += mem[p->pc + 1 + i];
		i++;
	}
	if (p->carry == 1)
		p->pc = dest;
}