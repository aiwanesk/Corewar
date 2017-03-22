/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:43:47 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/22 11:30:08 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"

int				main(int argc, char **argv)
{
	t_options		opts;
	t_env			env;

	(void)argc;
	opts = parse_options(&argv[1],
			(t_options){.nbchampions = 0, .id[0] = 0, .error = 0,
			.dumpcycle = -1, .ui = FALSE});
	if (opts.nbchampions < 1 || opts.error == 1)
	{
		ft_putstr_fd("Please check option : ", STDERR);
		ft_putendl_fd("[-dump nbr_cycles] [[-n number] champion1.cor]", STDERR);
	}
	else if (error_options(opts))
	{
		if ((env = init_core(opts)).error)
		{
			ft_putstr(RED);
			ft_putendl_fd(env.s_error, STDERR);
			ft_putstr(C_NONE);
			return (0);
		}
		core(env);
		protocol_end(env);
	}
	return (0);
}
