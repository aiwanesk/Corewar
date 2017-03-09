/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:18:38 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/08 18:33:10 by aiwanesk         ###   ########.fr       */
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
	printf("instruction ZJMP \n");
//	char test[2];
	uint32_t	test = 0;
	while (i < arg.total_to_read[0])
	{
		test <<= 8;
		test |= mem[p->pc + i + 1];
		printf("%.4x\n", test);
		i++;
//		test[0] = mem[p->pc + i + 1];
//		test[1] = mem[p->pc + i + 2];
//		break;
	//	if (dest == 0)
	//		dest = 1;
	//	dest *= mem[p->pc + 1 + i];
	//	printf("int = %d\n", dest);
	//	i++;
	}
	printf("destination = %d\n", (p->pc  + test) % MEM_SIZE);
	printf("carry = %d\n", p->carry);
	if (p->carry == 1)
		p->pc += (test) % MEM_SIZE;
	else
		p->pc = (p->pc + i + 1) % MEM_SIZE;
	p->nb_cycle -= 20;
}
