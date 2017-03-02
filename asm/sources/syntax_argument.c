#include <libft.h>
#include <op.h>
#include <opcode.h>
#include <struct_lex.h>
#include <syntax_analyser.h>

#include <stdio.h> // TODO DEBUG

static void		st_is_valid(char *arg, char *mask, unsigned int i)
{
	if (arg[0] == 'r')
	{
		if (ft_atoi(&arg[1]) <= 16 && ft_atoi(&arg[1]) > 0)
			*mask = T_REG;
	}
	else
	{
		*mask = T_IND;
		if (arg[0] == DIRECT_CHAR)
		{
			*mask = T_DIR;
			++arg;
		}
		if (arg[0] == LABEL_CHAR)
			return ;
		else
		{
			i = (arg[0] == '-') ? 1 : 0;
			while (arg[i] && arg[i] != SEPARATOR_CHAR && ft_isdigit(arg[i]))
				++i;
			if (arg[i] != '\0' && arg[i] != SEPARATOR_CHAR && !ft_isspace(arg[i]))
				*mask = 0;
		}
	}
}

void			syn_check_arg(t_lex *lex, t_op op, int pos)
{
	unsigned int	i;
	unsigned int	nbr;
	char			*code;
	char			mask;

	i = 0;
	nbr = 0;
	code = &lex->code[pos];
	while (code[i])
	{
		if (i == 0 || code[i - 1] == SEPARATOR_CHAR)
		{
			mask = 0;
			st_is_valid(&code[i], &mask, 0);
			if (mask == 0)
				syntax_error(lex, pos + i, "Bad argument");
			if (!(op.arg[nbr] & mask) && !(op.arg[nbr] & mask) && !(op.arg[nbr] & mask))
				syntax_error(lex, pos + i, "Bad argument");
			++nbr;
		}
		++i;
	}
}
