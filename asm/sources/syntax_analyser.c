#include <libft.h>
#include <op.h>
#include <struct_lex.h>
#include <opcode.h>
#include <lexical_analyser.h>
#include <syntax_analyser.h>

static void		st_label(t_lex *lex)
{
	unsigned int	i;

	i = 0;
	while (lex->code[i] && lex->code[i] != LABEL_CHAR && \
			ft_strchr(LABEL_CHARS, lex->code[i]) != 0x00)
		++i;
	if (lex->code[i] != LABEL_CHAR)
		syntax_error(lex, i, "Name label, not supported caracter");
}

static void		st_cmd(t_lex *lex)
{
	unsigned int	i;
	int				guil;

	i = 0;
	guil = 0;
	while (lex->code[i] && !ft_isspace(lex->code[i]))
		++i;
	if (!lex_is_cmd(lex->code, i))
		syntax_error(lex, i, "Command name not found");
	while (lex->code[i] && guil < 2)
	{
		if (lex->code[i] == '"')
			++guil;
		++i;
	}
	while (lex->code[i] && ft_isspace(lex->code[i]))
		++i;
	if (guil != 2)
		syntax_error(lex, i, "Bad string delimiter");
	if (lex->code[i])
		syntax_error(lex, i, "Bad delimiter");
}

static void		st_opcode(t_lex *lex, unsigned int j)
{
	unsigned int	i;
	char			nbr;
	t_op			op;

	i = 0;
	nbr = 1;
	while (lex->code[i] && !ft_isspace(lex->code[i]))
		++i;
	lex->code[i] = '\0';
	op = get_by_name(lex->code);
	lex->code[i] = ' ';
	if (op.code == 0x00)
		syntax_error(lex, 0, "Bad instruction");
	j = i;
	while (lex->code[i])
	{
		if (lex->code[i] == SEPARATOR_CHAR)
			++nbr;
		++i;
	}
	if (op.nbrarg != nbr)
		syntax_error(lex, 0, "Bad number argument instruction");
	while (lex->code[j] && ft_isspace(lex->code[j]))
		++j;
	syn_check_arg(lex, op, j);
}

void			syn_analyser(t_lex *lex)
{
	while (lex)
	{
		if (lex->type == LABEL)
			st_label(lex);
		else if (lex->type == CMD)
			st_cmd(lex);
		else if (lex->type == OPCODE)
			st_opcode(lex, 0);
		lex = lex->next;
	}
}
