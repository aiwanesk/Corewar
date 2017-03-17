/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:30:50 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:30:50 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <op.h>
#include <compilateur.h>
#include <label.h>

static t_lab	**st_get(void)
{
	static t_lab	*label = 0x00;

	return (&label);
}

static void		st_new(unsigned int label, unsigned int size)
{
	t_lab			**lab;
	t_lab			*tmp;
	t_lab			*new;

	lab = st_get();
	new = (t_lab *)malloc(sizeof(t_lab));
	new->label[0].hash = label;
	new->label[0].addr = size;
	new->label[1].hash = 0;
	new->libre = 1;
	new->next = 0x00;
	if (*lab == 0x00)
		*lab = new;
	else
	{
		tmp = lab_get();
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_lab			*lab_get(void)
{
	return (*(st_get()));
}

void			lab_new(t_lex *lex, unsigned int size)
{
	t_lab			*lab;
	unsigned int	i;
	unsigned int	label;

	lab = lab_get();
	i = 0;
	while (lex->code[i] != LABEL_CHAR)
		++i;
	lex->code[i] = '\0';
	label = djb2(lex->code);
	lab_check(lex, label);
	while (lab && lab->libre == 0)
		lab = lab->next;
	if (lab == 0x00)
		st_new(label, size);
	else
	{
		i = 0;
		while (lab->label[i].hash != 0)
			++i;
		lab->label[i].hash = label;
		lab->label[i].addr = size;
		lab->label[i + 1].hash = 0;
		lab->libre = (i + 1 == SIZE_ARRAY) ? 0 : 1;
	}
}

void			lab_free(void)
{
	t_lab		*lab;
	t_lab		*tmp;

	lab = lab_get();
	while (lab)
	{
		tmp = lab;
		lab = lab->next;
		free(tmp);
	}
}
