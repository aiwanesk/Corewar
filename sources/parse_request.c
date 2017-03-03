#include "cpu.h"

int						int_to_read(char *t, int i, int op)
{
	char	tmp[3];
	int		ret;

	tmp[0] = t[i];
	tmp[1] = t[i + 1];
	tmp[2] = '\0';
	ret = 0;
	if (ft_strcmp(tmp, "11") == 0)
		ret = 2;
	else if (ft_strcmp(tmp, "01") == 0)
		ret = 1;
	else if (ft_strcmp(tmp, "10") == 0 && op >= 10 && op != 13)
		ret = (2);
	else if (ft_strcmp(tmp, "10") == 0 && op < 10)
		ret =  (4);
	return (ret);
}

struct s_arg			parsing_request(t_process *p, unsigned char memory[MEM_SIZE])
{
	int				op_code;
	struct s_arg	ret;
	char			*tmp;

	op_code = memory[p->pc % MEM_SIZE];
	if (op_code < 17 && op_code >= 0 && g_tab[op_code].cycle <= p->nb_cycle)
	{
		//read_arg
		if (op_code == 1 || op_code == 9 || op_code == 12)
		{
			if (op_code == 1)
			{
				ret.total_to_read[0] = 4;
				ret.total_to_read[1] = 0;
				ret.total_to_read[2] = 0;
				ret.total_to_read[3] = 0;
			}
			else
			{
				ret.total_to_read[0] = 2;
				ret.total_to_read[1] = 0;
				ret.total_to_read[2] = 0;
				ret.total_to_read[3] = 0;
			}
		}
		else
		{
			tmp = ft_strdup(get_data_from_hex( memory[(p->pc + 1) % MEM_SIZE]).val);
			int i = 0;
			for (; i < 8; i += 2)
			{
				ret.total_to_read[i / 2] = int_to_read(tmp, i, op_code);
			}
			free(tmp);
		}
	}
	else
		p->nb_cycle -= 1;
	return (ret);
}