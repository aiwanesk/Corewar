/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:18:38 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 12:47:31 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
**zjmp : Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage des
**paramètres derrière cette opération dont l’opcode est de 9. Elle prendra un in
*/

void					apply_zjmp(t_process *p, t_env *env)
{
	(void)p;
	(void)env;
}
