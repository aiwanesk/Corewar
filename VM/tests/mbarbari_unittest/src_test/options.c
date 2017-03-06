#include "core.h"
#include "op.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

t_options test1(void)
{
	t_options test;
	char		*data[] = {
		"-dump",
		"200",
		"-n",
		"4",
		"champion.cor",
		"champion1.cor",
		"champion2.cor",
		"champion3.cor",
		NULL
	};
	bzero(&test, sizeof(t_options));
	return (parse_options(data, test));
}

t_options test2(void)
{
	t_options test;
	char		*data[] = {
		"200",
		"-n",
		"4",
		"champion.cor",
		"champion1.cor",
		"champion2.cor",
		NULL
	};
	bzero(&test, sizeof(t_options));
	return (parse_options(data, test));
}

t_options test3(void)
{
	t_options test;
	char		*data[] = {
		"champion.cor",
		"champion1.cor",
		"champion2.cor",
		"champion3.cor",
		NULL
	};
	bzero(&test, sizeof(t_options));
	return (parse_options(data, test));
}

t_options test4(void)
{
	t_options test;
	char		*data[] = {
		NULL
	};
	bzero(&test, sizeof(t_options));
	return (parse_options(data, test));
}

t_options test5(void)
{
	t_options test;
	char		*data[] = {
		"-n",
		"4",
		"champion.cor",
		"champion1.cor",
		"champion2.cor",
		"champion3.cor",
		"champion5.cor",
		NULL
	};
	bzero(&test, sizeof(t_options));
	return (parse_options(data, test));
}

t_options test6(void)
{
	t_options test;
	char		*data[] = {
		"-n",
		"6",
		"champion.cor",
		"champion1.cor",
		"champion2.cor",
		"champion3.cor",
		"champion5.cor",
		"champion6.cor",
		"champion7.cor",
		NULL
	};
	bzero(&test, sizeof(t_options));
	return (parse_options(data, (t_options){.dumpcycle = 0}));
}

void	options_read(t_options opt)
{
	unsigned int		i;

	dprintf(1, "opt ERROR : %d\nopt -dump : %d\nopt -n : %d\n", opt.error, opt.dumpcycle, opt.id[0]);
	i = 0;
	while (i < opt.nbchampions)
	{
		dprintf(1, "Champion[%d] : %s - id : %d\n", i, opt.champions[i], opt.id[i]);
		++i;
	}
}

int		main(void)
{
	int			i;
	int			b;
	int			a;
	int			c;
	t_process	process[10];
	t_options	opt[10];

	dprintf(1, C_MAGENTA"Test[0] Normal -dump 200 -n 4 champion.c ... champion3.cor%s\n", C_NONE);
	opt[0] = test1();
	options_read(opt[0]);
	dprintf(1, C_MAGENTA"\nTest[1] 200 -n 4 champion.c ... champion2.cor%s\n", C_NONE);
	opt[1] = test2();
	options_read(opt[1]);
	dprintf(1, C_MAGENTA"\nTest[2] champion.c ... champion3.cor%s\n", C_NONE);
	opt[2] = test3();
	options_read(opt[2]);
	dprintf(1, C_MAGENTA"\nTest[3] NULL%s\n", C_NONE);
	opt[3] = test4();
	options_read(opt[3]);
	dprintf(1, C_MAGENTA"\nTest[4] -n 4 champion.c ... champion4.cor%s\n", C_NONE);
	opt[4] = test5();
	options_read(opt[4]);
	dprintf(1, C_MAGENTA"\nTest[5] -n 6 champion.c ... champion4.cor%s\n", C_NONE);
	opt[5] = test6();
	options_read(opt[5]);
	#ifdef PROCESS
		dprintf(1, "\n");
		c = -1;
		while (++c < 6)
		{
			i = -1;
			while (++i < (int)opt[c].nbchampions)
			{
				process[i] = new_process(opt[c], i);
				dprintf(1, "process.id = %d\nprocess.pc = %u\nprocess.reg[0] = %s\n",
						process[i].id, process[i].pc,
						process[i].reg[0] == process[i].id ? "OK" : "KO");
				dprintf(1, "process.alive = %u\nprocess.nb_cycle = %u\nprocess.carry = %u\n\n\n",
						process[i].alive, process[i].nb_cycle, process[i].carry);
				++i;
			}
			check_random(process, opt[c].nbchampions);
			b = -1;
			while (++b < (int)opt[c].nbchampions)
			{
				a = -1;
				while (++a < (int)opt[c].nbchampions)
				{
					if (a != b && process[a].id == process[b].id)
						dprintf(1, "KO CHECK RANdom");
				}
			}
		}
	#endif
	return (0);
}
