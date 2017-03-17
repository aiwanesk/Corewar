/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:58:22 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 15:58:35 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "core.h"
#include "libft.h"

void				check_random(t_process process[], int n)
{
	int		i;
	int		a;

	i = -1;
	while (++i < n)
	{
		a = -1;
		while (++a < n)
		{
			if (a != i && process[a].id == process[i].id)
			{
				process[i].id = random_uint32();
				i = -1;
				break ;
			}
		}
	}
}

void				ft_putnbr_uint32(uint32_t nbr)
{
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	ft_putchar('0' + (nbr % 10));
}

uint32_t			djb2(const char *str)
{
	uint32_t		hash;
	int				c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

uint32_t			random_uint32(void)
{
	int			fd;
	char		buf[255];

	if ((fd = open("/dev/urandom", O_RDONLY)) < 0)
	{
		ft_putendl("Error opening urandom");
		return (0);
	}
	buf[read(fd, buf, 200)] = '\0';
	return (djb2(buf));
}
