/*
 * ****************
** HEADER MBA
** ****************
*/

#include "libft.h"

static int		test_integer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
	}
	return (TRUE);
}

t_options		parse_options(const char **data, t_options opt)
{
	int		i;
	int		champ;

	i = -1;
	opt = (t_options) {.nbcycle = };
	while (data != NULL)
	{
		if (ft_strcmp(data, "-dump") == 0)
		{
			if (test_integer(++data))
				opt.nbcycle = ft_atoi(data);
			else
				return ((t_opt) {.error = 1});
		}
		else if (ft_strcmp(data, "-n"))
		{
			if ((opt.nbchampions = ft_atoi(++data)) > 255)
				return ((t_opt) {.error = 1});
			champions[(champ = opt.nbchampions)] = NULL;
			while (--champ > -1)
				champions[champ] = *(++data);
		}
		++data;
	}
	return (opt);
}
