/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:58:59 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 20:13:26 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "core.h"
#include "libft.h"

int32_t			convert_endianness(unsigned int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

static t_env		check_header(t_env env, header_t head)
{
	if (convert_endianness(head.magic) != COREWAR_EXEC_MAGIC)
		return ((t_env){.error = 1, .s_error = "File's not a corewar binary"});
	else if (convert_endianness(head.prog_size) > CHAMP_MAX_SIZE)
		return ((t_env){.error = 1, .s_error = "Champions file is too big"});
	return (env);
}

t_env				load_champion(t_env env, t_options opt, int id)
{
	int			fd;
	header_t	head;

	env.error = 0;
	if ((fd = open(opt.champions[id], O_RDONLY)) < 0)
		return ((t_env){.error = 1, .s_error = "File not exists"});
	else if ((read(fd, &head, sizeof(header_t))) != sizeof(header_t))
		return ((t_env){.error = 1, .s_error = "Can't find binary's header"});
	else if ((env = check_header(env, head)).error == 1)
		return (env);
	else if ((read(fd, &env.memory[env.process[id].pc],
		convert_endianness(head.prog_size))) !=
			convert_endianness(head.prog_size))
		env = (t_env){.error = 1, .s_error = "Size of program doesn't match"};
	else
		ft_strncpy(env.process[id].name, head.prog_name, PROG_NAME_LENGTH);
	protocol_lmz(env, id, convert_endianness(head.prog_size), head.prog_name);
	close(fd);
	return (env);
}
