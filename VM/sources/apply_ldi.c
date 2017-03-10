/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:07:16 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 12:47:07 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** ldi : ldi,on opcode est 0x0a. Au lieu de ça, ca prend 2 index et 1 registre,
** additionne les 2 premiers, traite ca comme une adresse, y lit une valeur de
** taille d’un registre et la met dans le 3eme.
*/

void				apply_ldi(t_process *process, t_env *env)
{
	(void)process;
	(void)env;
}
