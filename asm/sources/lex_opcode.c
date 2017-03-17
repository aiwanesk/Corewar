/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:31:18 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:31:19 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <struct_lex.h>

void				lex_add_opcode(char *str, unsigned int *pos, int ligne)
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
	new_lex(str, OPCODE, ligne);
}
