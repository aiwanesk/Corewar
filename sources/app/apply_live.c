#include "../../includes/cpu.h"

void				apply_live(t_process *process, char memory[MEM_SIZE])
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < 4)
	{
		total += memory[process->pc + i];
		i++;
	}
	/*if (process->alive)
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
	}*/
	//=TODO comment suis je sense savoir comment se portent les autres process sans requetE?
}
