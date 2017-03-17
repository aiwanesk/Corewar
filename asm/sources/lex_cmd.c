/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:31:07 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:31:08 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <struct_lex.h>

unsigned int		lex_is_cmd(char *str, unsigned int size)
{
	if (ft_strncmp(str, NAME_CMD_STRING, size) == 0 || \
		ft_strncmp(str, COMMENT_CMD_STRING, size) == 0)
		return (1);
	return (0);
}

void				lex_add_cmd(char *str, unsigned int *pos, int ligne)
{
	unsigned int	i;
	char			comment;

	i = 0;
	comment = 0;
	while (str[i] && str[i] != COMMENT_CHAR && str[i] != '\n')
		++i;
	if (str[i] == COMMENT_CHAR)
		comment = 1;
	str[i] = '\0';
	if (comment)
	{
		++i;
		while (str[i] && str[i] != '\n')
			++i;
	}
	*pos += i;
	new_lex(str, CMD, ligne);
}
