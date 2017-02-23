#include "virtual_machine.h"
#include "op.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

t_options test1(void)
{
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

	return (parse_options(data, (t_options){0}));
}

t_options test2(void)
{
	char		*data[] = {
		"200",
		"-n",
		"4",
		"champion.cor",
		"champion1.cor",
		"champion2.cor",
		NULL
	};

	return (parse_options(data, (t_options){0}));
}

t_options test3(void)
{
	char		*data[] = {
		"champion.cor",
		"champion1.cor",
		"champion2.cor",
		"champion3.cor",
		NULL
	};

	return (parse_options(data, (t_options){0}));
}

t_options test4(void)
{
	char		*data[] = {
		NULL
	};

	return (parse_options(data, (t_options){0}));
}

t_options test5(void)
{
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

	return (parse_options(data, (t_options){.dumpcycle = 0}));
}

void	options_read(t_options opt)
{
	unsigned int		i;

	dprintf(1, "opt ERROR : %d\nopt -dump : %d\nopt -n : %d\n", opt.error, opt.dumpcycle, opt.nbchampions);
	i = 0;
	while (i < opt.nbchampions)
	{
		dprintf(1, "Champion[%d] : %s\n", i, opt.champions[i]);
		++i;
	}
}

int		main(void)
{
	dprintf(1, C_MAGENTA"Test Normal -dump 200 -n 4 champion.c ... champion3.cor%s\n", C_NONE);
	options_read(test1());
	dprintf(1, C_MAGENTA"\nTest 200 -n 4 champion.c ... champion2.cor%s\n", C_NONE);
	options_read(test2());
	dprintf(1, C_MAGENTA"\nTest champion.c ... champion3.cor%s\n", C_NONE);
	options_read(test3());
	dprintf(1, C_MAGENTA"\nTest NULL%s\n", C_NONE);
	options_read(test4());
	dprintf(1, C_MAGENTA"\nTest -n 4 champion.c ... champion4.cor%s\n", C_NONE);
	options_read(test5());
}
