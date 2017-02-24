#include "virtual_machine.h"

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
