/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:49:01 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/20 15:46:00 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "core.h"
#include "libft.h"

void		protocol_lmz(t_env env, int id, int32_t size, char *str)
{
	if (!env.ui)
		return ;
	ft_putstr("UI_PROTOCOL LMZ ");
	ft_putnbr_uint32(env.process[id].idlive);
	ft_putstr("-");
	ft_putnbr_uint32(env.process[id].pc);
	ft_putstr("-");
	ft_putnbr_uint32(size);
	ft_putstr("-");
	ft_putendl(str);
}

void		protocol_pc(t_env env, t_process process, int32_t addr)
{
	if (!env.ui)
		return ;
	if (addr < 0)
		addr += MEM_SIZE;
	ft_putstr("UI_PROTOCOL PC ");
	ft_putnbr_uint32(process.idlive);
	ft_putstr("-");
	ft_putnbr_uint32(addr);
	ft_putendl("");
}

void		protocol_mem(t_env env, t_process process, int32_t addr)
{
	int16_t		a;

	if (!env.ui)
		return ;
	a = (int16_t)addr;
	ft_putstr("UI_PROTOCOL MEM ");
	ft_putnbr_uint32(process.idlive);
	ft_putstr("-");
	ft_putnbr(((a < 0) ? a + MEM_SIZE : a % MEM_SIZE));
	ft_putstr("\nUI_PROTOCOL MEM ");
	ft_putnbr_uint32(process.idlive);
	ft_putstr("-");
	ft_putnbr(((a < 0) ? a + MEM_SIZE : a % MEM_SIZE) + 1);
	ft_putstr("\nUI_PROTOCOL MEM ");
	ft_putnbr_uint32(process.idlive);
	ft_putstr("-");
	ft_putnbr(((a < 0) ? a + MEM_SIZE : a % MEM_SIZE) + 2);
	ft_putstr("\nUI_PROTOCOL MEM ");
	ft_putnbr_uint32(process.idlive);
	ft_putstr("-");
	ft_putnbr(((a < 0) ? a + MEM_SIZE : a % MEM_SIZE) + 3);
	ft_putendl("");
}

void		protocol_win(t_env env, t_process process)
{
	if (!env.ui)
		return ;
	ft_putstr("UI_PROTOCOL WIN ");
	ft_putnbr_uint32(process.idlive);
	ft_putendl("");
}

void		protocol_lc(t_env env)
{
	int		i;

	if (!env.ui)
		return ;
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (env.idlive[i] < 0)
			continue ;
		ft_putstr("UI_PROTOCOL LC ");
		ft_putnbr_uint32(env.idlive[i]);
		ft_putstr("-");
		ft_putnbr_uint32(env.live[i]);
		ft_putstr("-");
		ft_putnbr_uint32(env.cycles);
		ft_putendl("");
	}
}
