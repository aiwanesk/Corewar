#include "cpu.h"

static void				normalize_len(struct s_data *d, int val)
{
	char		*tmp;
	int			size;
	int			i;

	tmp = ft_itoa(val);
	size = 8 - ft_strlen(tmp);
	i = 0;
	while (i != size)
	{
		d->val[i] = '0';
		i++;
	}
	size = 0;
	while (i != 8)
	{
		d->val[i] = tmp[size];
		i++;
		size++;
	}
	free(tmp);
}

struct s_data			get_data_from_hex(int val)
{
	struct s_data		ret;

	val = int_to_bin(val);
	normalize_len(&ret, val);
	return (ret);
}
