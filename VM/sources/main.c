#include "core.h"
#include "libft.h"

int				main(int argc, char **argv)
{
	t_options		opts;
	t_env			env;

	(void)argc;
	opts = parse_options(&argv[1], (t_options){.error = 0, .dumpcycle = -1});
	if (opts.nbchampions < 2 || opts.error == 1)
	{
		ft_putstr_fd("Please check option : ", STDERR);
		ft_putendl_fd("[-dump nbr_cycles] [[-n number] champion1.cor]", STDERR);
	}
	else
	{
		if ((env = init_core(opts)).error)
		{
			ft_putstr(RED);
			ft_putendl_fd(env.s_error, STDERR);
			return (0);
		}
		core(env, 0);
	}
	return (0);
}
