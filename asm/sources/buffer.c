/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:30:13 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:30:14 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <libft.h>
#include <op.h>
#include <compilateur.h>

static unsigned int		st_check_extension(char *namefile)
{
	unsigned int		size;

	size = ft_strlen(namefile);
	if (size > 2 && namefile[size - 1] == 's' && namefile[size - 2] == '.')
		return (1);
	write(2, "Bad file extension\n", 19);
	return (0);
}

char					*bufferise(char *namefile)
{
	int				fd;
	char			*buffer;
	unsigned long	size;

	if (st_check_extension(namefile) == 0)
		return (0x00);
	fd = open(namefile, O_RDONLY);
	if (fd == -1)
	{
		perror(namefile);
		return (0x00);
	}
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	buffer[0] = '\0';
	if (read(fd, buffer, size) == -1)
	{
		perror(namefile);
		free(buffer);
		return (0x00);
	}
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}
