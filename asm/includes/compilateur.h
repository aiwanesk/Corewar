/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compilateur.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:32:11 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:32:12 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPILATEUR_H
# define COMPILATEUR_H

# include <struct_lex.h>
# include <label.h>
# include <bytecode.h>

/*
** buffer.c
*/
char			*bufferise(char *namefile);

/*
** main.c
*/
void			exit_main(void);

/*
** djb2.c
*/
unsigned int	djb2(char *str);

/*
** compilation.c
*/
unsigned int	rev_indian(unsigned int n);
void			compilation(t_lex *lex);

/*
** cmd.c
*/
void			cmd_use(char *code);

#endif
