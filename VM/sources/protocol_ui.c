/*
 * ****************
** HEADER MBA
** ****************
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> //TODO : del
#include "core.h"
#include "libft.h"

void		protocol_lmz(t_env env, int id, uint32_t size, char *str)
{
	if (!env.ui)
		return ;
	ft_putstr("UI_PROTOCOL LMZ ");
	ft_putnbr_uint32(env.process[id].id);
	ft_putstr("-");
	ft_putnbr_uint32(env.process[id].pc);
	ft_putstr("-");
	ft_putnbr_uint32(size);
	ft_putstr("-");
	ft_putendl(str);
}

void		protocol_pc(t_env env, uint32_t addr)
{
	if (!env.ui)
		return ;
	ft_putstr("UI_PROTOCOL PC ");
	ft_putnbr_uint32(addr);
	ft_putendl("");
}

void		protocol_mem(t_env env, t_process process, uint32_t addr)
{
	if (!env.ui)
		return ;
	ft_putstr("UI_PROTOCOL MEM ");
	ft_putnbr_uint32(process.id);
	ft_putstr("-");
	ft_putnbr_uint32(addr);
	ft_putstr("\nUI_PROTOCOL MEM ");
	ft_putnbr_uint32(process.id);
	ft_putstr("-");
	ft_putnbr_uint32(addr + 1);
	ft_putstr("\nUI_PROTOCOL MEM ");
	ft_putnbr_uint32(process.id);
	ft_putstr("-");
	ft_putnbr_uint32(addr + 2);
	ft_putstr("\nUI_PROTOCOL MEM ");
	ft_putnbr_uint32(process.id);
	ft_putstr("-");
	ft_putnbr_uint32(addr + 3);
	ft_putendl("");
}

void		protocol_win(t_env env, t_process process)
{
	if (!env.ui)
		return ;
	ft_putstr("UI_PROTOCOL PC ");
	ft_putnbr_uint32(process.id);
	ft_putendl("");
}

void		protocol_lc(t_env env)
{
	unsigned int		i;

	if (!env.ui)
		return ;
	i = 0;
	while (i < env.nbprocess)
	{
		ft_putstr("UI_PROTOCOL LC ");
		ft_putnbr_uint32(env.process[i].id);
		ft_putstr("-");
		ft_putnbr_uint32(env.process[i].alive);
		ft_putstr("-");
		ft_putnbr_uint32(env.cycles);
		ft_putendl("");
		++i;
	}
}

void		protocol_sleep(t_env env)
{
	if (!env.ui)
		return ;
	usleep(10000);
}
