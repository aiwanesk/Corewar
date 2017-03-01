#include <libft.h>
#include <op.h>

int				syn_is_valid(char *arg)
{
	unsigned int	i;
	char			ret;

	ret = 0;
	if (arg[0] == 'r')
	{
		if (ft_atoi(&arg[1]) <= 16 && ft_atoi(&arg[1]) > 0)
			ret = 1;
	}
	else
	{
		if (arg[1] == LABEL_CHAR)
			ret = 1;
		else
		{
			i = 1;
			while (arg[i] && arg[i] != SEPARATOR_CHAR && ft_isdigit(arg[i]))
				++i;
			if (arg[i] == '\0' || arg[i] == SEPARATOR_CHAR)
				ret = 1;
		}
	}
	return (ret);
}
