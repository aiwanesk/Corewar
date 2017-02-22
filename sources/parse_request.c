#include "../includes/parsing_request.h"

/*static*/ int		get_op_code(char a, char b)
{
	static char	cmp[16] = "123456789abcdef";
	int			i;

	if (a == '1')
		return (16);
	i = 0;
	while (cmp[i])
	{
		if (cmp[i] == b)
			return (i + 1);
		i++;
	}
	return (0);
}

void			parsing_request(char *b)
{
	int		op_code;

	if ((op_code = get_op_code(b[0], b[1])) <= 0)
		exit_error("invalid op code");
}
