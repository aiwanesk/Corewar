/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:30:19 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:30:19 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>
#include <op.h>
#include <header.h>
#include <error.h>
#include <compilateur.h>
#include <label.h>
#include <opcode.h>
#include <bytecode.h>

static char			**st_get(void)
{
	static char		*bytecode = 0x00;

	return (&bytecode);
}

void				write_bytecode(unsigned int size)
{
	int				fd;
	unsigned int	namesize;
	char			*name;

	namesize = ft_strlen(err_name(0x00));
	name = (char *)malloc(sizeof(char) * (namesize + 3));
	ft_memcpy(name, err_name(0x00), namesize);
	ft_memcpy(&name[namesize - 1], "cor\0", 4);
	fd = open(name, O_CREAT | O_WRONLY, 00744);
	if (fd == -1)
	{
		perror(name);
		free(name);
		free(*(st_get()));
		exit_main();
	}
	write_header(fd);
	write(fd, *(st_get()), size);
	free(name);
	free(*(st_get()));
	close(fd);
}

void				byt_add(char *mem, unsigned int size)
{
	static unsigned int		pos = 0;
	static unsigned int		maxsize = 1024;
	unsigned int			i;
	char					**bytecode;

	bytecode = st_get();
	if (*bytecode == 0x00)
		*bytecode = (char *)malloc(sizeof(char) * (maxsize + 1));
	if (pos + size >= maxsize)
	{
		maxsize += 1024;
		*bytecode = (char *)realloc(*bytecode, sizeof(char) * (maxsize + 1));
	}
	i = 0;
	while (i < size)
	{
		(*bytecode)[pos + i] = mem[i];
		++i;
	}
	pos += size;
}

void				byt_new(t_lex *lex)
{
	static unsigned int		pos = 0;
	t_op					op;
	unsigned int			i;

	i = 0;
	while (!ft_isspace(lex->code[i]))
		++i;
	lex->code[i] = '\0';
	op = get_by_name(lex->code);
	lex->code[i] = ' ';
	byt_add(&op.code, 1);
	while (ft_isspace(lex->code[i]))
		++i;
	if (byt_if_encode(op))
		byt_encode(&lex->code[i]);
	pos += byt_argument(lex, op, pos);
	pos += (byt_if_encode(op)) ? 2 : 1;
}

unsigned int		byt_encode(char *code)
{
	unsigned int	i;
	char			enc;

	i = 0;
	enc = 0;
	while (code[i])
	{
		if (i == 0 || code[i - 1] == SEPARATOR_CHAR)
		{
			if (code[i] == 'r')
				enc |= REG_CODE;
			else if (code[i] == DIRECT_CHAR)
				enc |= DIR_CODE;
			else
				enc |= IND_CODE;
			enc = (enc << 2);
		}
		++i;
	}
	while (!(enc & 0xC0))
		enc = (enc << 2);
	byt_add(&enc, 1);
	return (1);
}
