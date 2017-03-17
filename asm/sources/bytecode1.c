/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:30:25 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:30:26 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <compilateur.h>
#include <struct_lex.h>
#include <label.h>
#include <opcode.h>
#include <bytecode.h>

static unsigned int		st_encode_reg(char *arg)
{
	char		n;

	++arg;
	n = (char)ft_atoi(arg);
	byt_add(&n, 1);
	return (1);
}

static unsigned int		st_encode_val(char *arg, t_op op)
{
	unsigned int	n;
	unsigned int	labelsize;

	labelsize = 2;
	if (*arg == DIRECT_CHAR)
	{
		labelsize = op.labelsize;
		++arg;
	}
	n = ft_atoi(arg);
	n = rev_indian(n);
	if (labelsize == 2)
		n = n >> 16;
	byt_add((char *)&n, labelsize);
	return (labelsize);
}

static unsigned int		st_encode_label(t_op op, t_lex *lex, int pos, int align)
{
	t_label				label;
	unsigned int		hash;
	unsigned int		i;
	char				tmp;
	char				*arg;

	i = 0;
	arg = get_arg(lex->code);
	arg = &arg[pos];
	if (*arg == DIRECT_CHAR)
		++arg;
	else
		op.labelsize = 2;
	while (arg[i] && arg[i] != SEPARATOR_CHAR && !ft_isspace(arg[i]))
		++i;
	tmp = arg[i];
	arg[i] = '\0';
	hash = djb2(&arg[1]);
	arg[i] = tmp;
	label = label_valid(lex, pos, hash);
	i = rev_indian(label.addr - align);
	if (op.labelsize == 2)
		i = i >> 16;
	byt_add((char *)&i, op.labelsize);
	return (op.labelsize);
}

char					*get_arg(char *code)
{
	unsigned int		i;

	i = 0;
	while (!ft_isspace(code[i]))
		++i;
	while (ft_isspace(code[i]))
		++i;
	return (&code[i]);
}

unsigned int			byt_argument(t_lex *lex, t_op op, unsigned int pos)
{
	char			*code;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	code = get_arg(lex->code);
	while (code[i])
	{
		if (i == 0 || code[i - 1] == SEPARATOR_CHAR)
		{
			if (code[i] == 'r')
				size += st_encode_reg(&code[i]);
			else
			{
				if (code[i] == LABEL_CHAR || code[i + 1] == LABEL_CHAR)
					size += st_encode_label(op, lex, i, pos);
				else
					size += st_encode_val(&code[i], op);
			}
		}
		++i;
	}
	return (size);
}
