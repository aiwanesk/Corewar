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

	env = (t_env) {0};
	ft_bzero(env.virtual_machine, MEM_SIZE);
	if (opt.nbcycle != 0)
		env.cycle_total = opt.nbcycle;
	return (env);
}

void			virtual_machine()
{

}

int				main(int argc, char **argv)
{
	t_options		opts;

	(void)argc;
	if ((opts = parse_options(&argv[1], (t_options){.error = 0})).error == 1)
	{
		ft_putstr_fd("Please check option : ", STDERR);
		ft_putendl_fd("[-dump nbr_cycles] [[-n number] champion1.cor]", STDERR);
	}
	else
		virtual_machine(init_virtual_machine(opts));
	return (0);
}
