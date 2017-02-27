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

t_options		parse_options(char **data, t_options opt)
{
	int		champ;

	if (*data && ft_strcmp(*data, "-dump") == 0)
	{
		if (!test_integer(*(++data)))
			return ((t_options) {.error = 1});
		opt.dumpcycle = ft_atoi(*data);
	}
	else if (*data && ft_strcmp(*data, "-n") == 0 && test_integer(*(data + 1)))
	{
		if ((opt.nbchampions = ft_atoi(*(++data))) > MAX_PLAYERS)
			return ((t_options) {.error = 1});
		opt.champions[(champ = opt.nbchampions)] = NULL;
		while (--champ > -1)
		{
			if (!*(data + 1))
				return ((t_options) {.error = 1});
			opt.champions[(opt.nbchampions - 1) - champ] = *(++data);
		}
	}
	if (*(data + 1))
		return (parse_options(data + 1, opt));
	else
		return (opt);
}
