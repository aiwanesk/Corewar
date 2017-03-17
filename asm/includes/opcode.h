/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:32:24 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:32:25 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPCODE_H
# define OPCODE_H

# define T_FORCE 8

typedef struct		s_op
{
	char			code;
	char			labelsize;
	char			nbrarg;
	unsigned int	hash;
	char			arg[3];
}					t_op;

/*
** opcode.c
*/
t_op				get_by_name(char *name);
t_op				get_by_code(char code);

#endif
