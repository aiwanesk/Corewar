/*
 * ****************
** HEADER MBA
** ****************
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "virtual_machine.h"
#include "libft.h"

int			process_alive(t_env env)
{
	(void)env;
	return (1);
}

t_env		load_champion(t_env env, t_options opt, int id)
{
	int			fd;
	t_header	head;

	if ((fd = open(opt.champions[id], O_RDONLY)) != -1)
		env = (t_env){.error = 1};
	else if (read(fd, &head, sizeof(t_header)) != sizeof(t_header))
		env = (t_env){.error = 1};
	else if (read(fd, &env.memory[env.process[id].pc], head.prog_size) !=
																head.prog_size)
		env = (t_env){.error = 1};
	else
		ft_strcpy(env.process[id].name, head.prog_name);
	close(fd);
	return (env);
}

t_process	new_process(t_options opt, int id)
{
	t_process	process;
	
	process.id = random_uint32();
	process.pc = (MEM_SIZE / opt.nbchampions) * id;
	process.reg[0] = process.id;
	process.alive = NBR_LIVE;
	process.nb_cycle = 0;
	process.carry = 0;
	return (process);
}

t_env		create_process(t_env env, t_options opt)
{
	uint32_t	i;

	i = 0;
	while (i < opt.nbchampions)
	{
		env.process[i] = new_process(opt, i);
		if ((env = load_champion(env, opt, i)).error == 1)
			return (env);
		++i;
	}
	check_random(env.process, opt.nbchampions);
	return (env);
}
