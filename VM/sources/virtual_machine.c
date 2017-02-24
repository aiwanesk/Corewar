/*
 * ****************
** HEADER MBA
** ****************
*/

#include "virtual_machine.h"
#include "libft.h"


static t_env	init_virtual_machine(t_options opt)
{
	t_env		env;

	ft_bzero(&env, sizeof(t_env));
	if (opt.dumpcycle > 0)
		env.isdump = TRUE;
	return (env);
}

int				winner(int		id)
{
	return (id);
}

int				virtual_machine(t_env env)
{
	uint32_t		id;

	if ((id = process_alive(env)) < 1)
		return (winner(id));
	//env.nb_cycle++;
	return (virtual_machine(env));
}

int				main(int argc, char **argv)
{
	t_options		opts;

	if (argc > MAX_ARGS_NUMBER + 1)
	{
		ft_putstr_fd("Too much argument", STDERR);
		ft_putendl_fd(" [[-n number] champion1.cor]", STDERR);
		return (-1);
	}
	opts = parse_options(&argv[1], (t_options){.error = 0, .dumpcycle = -1});
	if (opts.error == 1)
	{
		ft_putstr_fd("Please check option : ", STDERR);
		ft_putendl_fd("[-dump nbr_cycles] [[-n number] champion1.cor]", STDERR);
	}
	else
		virtual_machine(init_virtual_machine(opts));
	return (0);
}
