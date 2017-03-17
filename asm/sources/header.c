/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:30:47 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:30:47 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <compilateur.h>
#include <header.h>

static header_t		*st_get(void)
{
	static header_t		header = {0xF383EA00, {0}, 0, {0}};

	return (&header);
}

void				head_data(enum e_data data, char *code)
{
	unsigned int	i;
	unsigned int	j;
	header_t		*head;

	head = st_get();
	i = 0;
	while (code[i] != '"')
		++i;
	++i;
	j = 0;
	while (code[i + j] != '"')
		++j;
	code[i + j] = '\0';
	if (data == NAME)
		ft_strncpy(head->prog_name, &code[i], PROG_NAME_LENGTH);
	else if (data == COMMENT)
		ft_strncpy(head->comment, &code[i], COMMENT_LENGTH);
}

void				head_size(int size)
{
	header_t		*head;

	head = st_get();
	head->prog_size = rev_indian(size);
}

void				write_header(int fd)
{
	write(fd, (void*)st_get(), sizeof(header_t));
}
