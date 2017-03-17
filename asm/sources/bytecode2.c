/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:30:31 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:30:31 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <struct_lex.h>
#include <opcode.h>
#include <bytecode.h>

static unsigned int		st_size(char *code, t_op op)
{
	unsigned int		i;
	unsigned int		size;

	i = 0;
	size = 0;
	while (code[i])
	{
		if (i == 0 || code[i - 1] == SEPARATOR_CHAR)
		{
			if (code[i] == 'r')
				size += 1;
			else if (code[i] == DIRECT_CHAR)
				size += op.labelsize;
			else
				size += 2;
		}
		++i;
	}
	return (size);
}

unsigned int			byt_size(t_lex *lex)
{
	t_op			op;
	unsigned int	i;
	unsigned int	size;

	size = 1;
	i = 0;
	while (!ft_isspace(lex->code[i]))
		++i;
	lex->code[i] = '\0';
	op = get_by_name(lex->code);
	lex->code[i] = ' ';
	while (ft_isspace(lex->code[i]))
		++i;
	if (byt_if_encode(op))
		size += 1;
	size += st_size(get_arg(lex->code), op);
	return (size);
}

int						byt_if_encode(t_op op)
{
	if ((op.arg[0] != T_REG && op.arg[0] != T_DIR && \
			op.arg[0] != T_IND && op.arg[0] != 0) || \
		(op.arg[1] != T_REG && op.arg[1] != T_DIR && \
			op.arg[1] != T_IND && op.arg[1] != 0) || \
		(op.arg[2] != T_REG && op.arg[2] != T_DIR && \
			op.arg[2] != T_IND && op.arg[2] != 0))
	{
		return (1);
	}
	return (0);
}
