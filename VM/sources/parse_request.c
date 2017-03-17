/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_request.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:24:25 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 16:18:37 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

int						int_to_read(char *t, int i, int op)
{
	char	tmp[3];
	int		ret;

	tmp[0] = t[i];
	tmp[1] = t[i + 1];
	tmp[2] = '\0';
	ret = 0;
	if (ft_strcmp(tmp, "11") == 0)
		ret = 2;
	else if (ft_strcmp(tmp, "01") == 0)
		ret = 1;
	else if (ft_strcmp(tmp, "10") == 0 && op >= 10 && op != 13)
		ret = (2);
	else if (ft_strcmp(tmp, "10") == 0 && op < 10)
		ret = (4);
	return (ret);
}

static void				get_total_live(struct s_arg *ret)
{
	ret->total_to_read[0] = 4;
	ret->total_to_read[1] = 0;
	ret->total_to_read[2] = 0;
	ret->total_to_read[3] = 0;
}

static void				get_total_else(struct s_arg *ret)
{
	ret->total_to_read[0] = 2;
	ret->total_to_read[1] = 0;
	ret->total_to_read[2] = 0;
	ret->total_to_read[3] = 0;
}

static void				norme(int op_code, struct s_arg *ret)
{
	if (op_code == 1)
		get_total_live(ret);
	else
		get_total_else(ret);
}

struct s_arg			parsing_request(t_process *p,
		unsigned char mem[MEM_SIZE])
{
	int				op_code;
	struct s_arg	ret;
	int				i;
	char			*tmp;

	i = 0;
	ret.total_to_read[0] = -1;
	op_code = mem[p->pc % MEM_SIZE];
	if (op_code < 17 && op_code >= 0)
	{
		if (op_code == 1 || op_code == 9 || op_code == 12)
			norme(op_code, &ret);
		else
		{
			tmp = ft_strdup(get_data_from_hex(mem[(p->pc + 1) % MEM_SIZE]).val);
			while (i < 8 && (i = i + 2))
				ret.total_to_read[(i - 2) / 2] = int_to_read(tmp, i - 2,
						op_code);
			free(tmp);
		}
	}
	else
		p->nb_cycle -= 1;
	return (ret);
}
