/*
 * ****************
** HEADER MBA
** ****************
*/

#include <stdio.h>
#include "libft.h"
#include "core.h"

static int		test_integer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int				error_options(t_options opt)
{
	if (opt.nbchampions > MAX_PLAYERS)
	{
		ft_putendl_fd("Too much player for this VM", STDERR);
		return (FALSE);
	}
	return (TRUE);
}

t_options		parse_options(char **data, t_options opt)
{
	opt.error = 0;
	if (*data && ft_strcmp(*data, "-dump") == 0)
	{
		if (!test_integer(*(++data)))
			return ((t_options) {.error = 1});
		opt.dumpcycle = ft_atoi(*data);
	}
	else if (*data && ft_strcmp(*data, "-n") == 0 && test_integer(*(data + 1)))
	{
		opt.id[0] = ft_atoi(*(++data));
		opt.nbchampions = 0;
		++data;
		while (data[opt.nbchampions] != NULL && opt.nbchampions <= MAX_PLAYERS)
		{
			opt.id[opt.nbchampions] = opt.id[0] + opt.nbchampions;
			opt.champions[opt.nbchampions] = data[opt.nbchampions];
			opt.nbchampions++;
		}
	}
	else if (*data && ft_strcmp(*data, "-ui") == 0)
		opt.ui = TRUE;
	if (*(data + 1))
		return (parse_options(data + 1, opt));
	else
		return (opt);
}
