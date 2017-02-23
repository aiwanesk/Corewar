#include "cpu.h"

void				apply_live(t_process *process)
{
	if (process->alive)
	{
		ft_putstr("un proccessus dit que le joueur ");
		ft_putstr(process->name);
		ft_putendl(" est en vie");
			ft_putendl_fd("un processus est en vie", 2);
	}
	else
	{
		ft_putstr("le proccessus dit que le joueur ");
		ft_putstr(process->name);
		ft_putendl(" est mort");
			ft_putendl_fd("un processus est mort", 2);
	}
}
