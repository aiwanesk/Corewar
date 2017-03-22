/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:49:25 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/22 11:31:32 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"

void			protocol_sleep(t_env env)
{
	if (!env.ui)
		return ;
	usleep(500);
}

void			protocol_end(t_env env)
{
	if (!env.ui)
		return ;
	ft_putendl("UI_PROTOCOL END ");
}
