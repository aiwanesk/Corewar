/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:31:47 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:31:47 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <error.h>
#include <struct_lex.h>

void			syntax_error(t_lex *lex, int pos, char *strerr)
{
	write(2, "Syntax error\n", 13);
	error(lex, pos, strerr);
}
