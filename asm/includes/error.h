/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:32:14 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:32:15 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <struct_lex.h>

/*
** error.c
*/
char			*err_name(char *namefile);
void			err_print_pos(int pos);
void			error(t_lex *lex, int pos, char *strerr);

#endif
