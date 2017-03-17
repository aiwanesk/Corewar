/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:30:55 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:30:56 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <error.h>
#include <struct_lex.h>
#include <compilateur.h>
#include <label.h>

static void		st_perso_error(t_lex *lex, int pos, char *strerr)
{
	int			ligne;

	ligne = lex->ligne;
	write(2, err_name(0x00), ft_strlen(err_name(0x00)));
	write(2, ":", 1);
	ft_putnbr_fd(lex->ligne, 2);
	write(2, ":", 1);
	ft_putnbr_fd(pos + 1, 2);
	write(2, ":\t", 2);
	write(2, strerr, ft_strlen(strerr));
	write(2, " '", 2);
	write(2, lex->code, ft_strlen(lex->code));
	write(2, "'\n", 2);
	while (lex && lex->ligne == ligne)
	{
		write(2, " ", 1);
		write(2, lex->code, ft_strlen(lex->code));
		lex = lex->next;
	}
	err_print_pos(pos);
}

static void		st_error(t_lex *lex, unsigned int label)
{
	t_lex			*tmp;

	tmp = get_lex();
	while (tmp)
	{
		if (tmp->type == LABEL)
		{
			if (label == djb2(tmp->code))
			{
				st_perso_error(tmp, 0, "Redefinition of label");
				break ;
			}
		}
		tmp = tmp->next;
	}
	error(lex, 0, "previous definition was here");
}

void			lab_check(t_lex *lex, unsigned int label)
{
	unsigned int	i;
	t_lab			*lab;

	lab = lab_get();
	while (lab)
	{
		i = 0;
		while (lab->label[i].hash != 0)
		{
			if (lab->label[i].hash == label)
				st_error(lex, label);
			++i;
		}
		lab = lab->next;
	}
}

t_label			label_valid(t_lex *lex, int pos, unsigned int label)
{
	unsigned int	i;
	t_lab			*lab;
	t_label			bad;

	lab = lab_get();
	bad.hash = 0;
	bad.addr = 0;
	while (lab)
	{
		i = 0;
		while (lab->label[i].hash != 0 && lab->label[i].hash != label)
			++i;
		if (lab->label[i].hash == label)
			return (lab->label[i]);
		lab = lab->next;
	}
	error(lex, pos, "No reference Symbol");
	return (bad);
}
