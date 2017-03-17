/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:32:19 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:32:20 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

enum	e_data
{
	NAME,
	COMMENT
};

/*
** header.h
*/
void			head_data(enum e_data data, char *code);
void			head_size(int size);
void			write_header(int fd);

#endif
