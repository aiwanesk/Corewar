#include "op_dict.h"

static struct s_dict				set_dict_0(void)
{
	struct s_dict		ret;

	ret.op_code = 1;
	ret.cycle = 10;
	return (ret);
}

struct s_dict						*init_dict(void)
{
	static int				init = 0;
	static struct s_dict	dict[16];

	if (init == 0)
	{
		dict[0] = set_dict_0();
		//dict[0] -> dict[n] = set_dict_(int(op_code));
		init++;
	}
	return (dict);
}
