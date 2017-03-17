/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:31:15 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:31:15 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <struct_lex.h>

void				lex_add_label(char *str, unsigned int *pos, int *ligne)
{
	unsigned int	i;
	char			comment;
	char			nl;

	comment = 0;
	nl = 0;
	i = 0;
	while (str[i] && str[i] != COMMENT_CHAR && str[i] != ' ' &&\
			str[i] != '\t' && str[i] != '\n')
		++i;
	if (str[i] == COMMENT_CHAR)
		comment = 1;
	if (str[i] == ' ' || str[i] == '\t')
		nl = 1;
	str[i] = '\0';
	if (comment)
	{
		++i;
		while (str[i] && str[i] != '\n')
			++i;
	}
	*pos += i;
	new_lex(str, LABEL, *ligne);
	if (nl)
		*ligne -= 1;
}
