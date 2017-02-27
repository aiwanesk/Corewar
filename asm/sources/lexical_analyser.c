#include <libft.h>
#include <op.h>
#include <struct_lex.h>
#include <lexical_analyser.h>

static void		st_analyse(char *src, unsigned int *pos, int *ligne)
{
	unsigned int	i;

	i = 0;
	while (src[i] && !ft_isspace(src[i]))
	{
		if (src[i] == COMMENT_CHAR)
		{
			while (src[i] && src[i] != '\n')
				++i;
			*pos += i;
			return ;
		}
		++i;
	}
	if (i > 0 && src[i - 1] == LABEL_CHAR)
		lex_add_label(src, pos, ligne);
	else if (lex_is_cmd(src, i))
		lex_add_cmd(src, pos, *ligne);
	else
		lex_add_opcode(src, pos, *ligne);
}

t_lex			*lex_analyser(char *src)
{
	int				ligne;
	unsigned int	pos;

	pos = 0;
	ligne = 1;
	while (src[pos])
	{
		if (!ft_isspace(src[pos]))
		{
			st_analyse(&src[pos], &pos, &ligne);
			++ligne;
		}
		else if (src[pos] == '\n')
			++ligne;
		++pos;
	}
	return (get_lex());
}
