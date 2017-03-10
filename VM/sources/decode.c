/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:26:29 by barbare           #+#    #+#             */
/*   Updated: 2017/03/09 16:28:32 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"
#include "libft.h"

void		decode(t_args args[3], uint32_t pc, unsigned char encoding)
{
	int			i;
	int			a;
	int			elem;

	ft_bzero(args, sizeof(t_args) * 3);
	a = MAX_ARGS;
	while (a > 0)
	{
		i = a - 1;
		elem = MAX_ARGS - a;
		args[elem].arg = (encoding >> (2 * (i + 1))) & 0x3;
		if (args[elem].arg == DIR_CODE)
			args[elem].length = length_label(pc);
		else if (args[elem].arg == IND_CODE)
			args[elem].length = T_DIR;
		else
			args[elem].length = T_REG;
		--a;
	}
}
