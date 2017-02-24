#include "virtual_machine.h"
#include "op.h"
#include <stdio.h>

t_options	test0(void)
{
	char		*data[] = {
		"-dump",
		"200",
		"-n",
		"2",
		"./ressources/Jules_Cesar.cor",
		"./ressources/test.cor",
		NULL
	};

	return (parse_options(data, (t_options){.dumpcycle = 0}));
}

t_options	test1(void)
{
	char		*data[] = {
		"-dump",
		"200",
		"-n",
		"3",
		"./ressources/Jules_Cesar.cor",
		"./ressources/test.cor",
		"./ressources/3615sleep.cor",
		NULL
	};

	return (parse_options(data, (t_options){.dumpcycle = 0}));
}

t_options	test2(void)
{
	char		*data[] = {
		"-dump",
		"200",
		"-n",
		"4",
		"./ressources/Jules_Cesar.cor",
		"./ressources/test.cor",
		"./ressources/3615sleep.cor",
		"./ressources/hades.cor",
		NULL
	};

	return (parse_options(data, (t_options){.dumpcycle = 0}));
}

t_options	test3(void)
{
	char		*data[] = {
		"-dump",
		"200",
		"-n",
		"4",
		"./ressources/Jules_Cesar.cor",
		"./ressources/test.cor",
		"./ressources/titi.cor",
		"./ressources/hades.cor",
		NULL
	};

	return (parse_options(data, (t_options){.dumpcycle = 0}));
}

t_options	test4(void)
{
	char		*data[] = {
		"-dump",
		"200",
		"-n",
		"4",
		"./ressources/Jules_Cesar.cor",
		"./ressources/test.cor",
		"./ressources/3615sleep.cor",
		"./ressources/0.t.cor",
		NULL
	};

	return (parse_options(data, (t_options){.dumpcycle = 0}));
}

int		main(void)
{
	t_options	opt;
	t_env		env;
	
	opt = test0();
	env= init_virtual_machine(opt);
	env = create_process(env, opt);
	if (env.error)
		dprintf(1, "ERROR IN ENV\n");
	else
		print_memory(env.memory);
	dprintf(1, "\n\n");
	opt = test1();
	env= init_virtual_machine(opt);
	env = create_process(env, opt);
	if (env.error)
		dprintf(1, "ERROR IN ENV\n");
	else
		print_memory(env.memory);
	dprintf(1, "\n\n");
	opt = test2();
	env= init_virtual_machine(opt);
	env = create_process(env, opt);
	if (env.error)
		dprintf(1, "ERROR IN ENV : %s\n", env.s_error);
	else
		print_memory(env.memory);
	dprintf(1, "\n\n");

	opt = test3();
	env= init_virtual_machine(opt);
	env = create_process(env, opt);
	if (env.error)
		dprintf(1, "ERROR IN ENV : %s\n", env.s_error);
	else
		print_memory(env.memory);
	dprintf(1, "\n\n");

	opt = test4();
	env= init_virtual_machine(opt);
	env = create_process(env, opt);
	if (env.error)
		dprintf(1, "ERROR IN ENV : %s\n", env.s_error);
	else
		print_memory(env.memory);
	return (0);
}
