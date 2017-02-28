#include <libft.h>
#include <op.h>
#include <compilateur.h>
#include <struct_lex.h>

char			*syn_err_name(char *namefile)
{
	static char		*name = 0x00;

	if (namefile && name == 0x00)
	{
		name = namefile;
		return (0x00);
	}
	return (name);
}

void			syntax_error(t_lex *lex, char *strerr)
{
	int			ligne;

	ligne = lex->ligne;
	write(2, "Syntax error\n", 13);
	write(2, syn_err_name(0x00), ft_strlen(syn_err_name(0x00)));
	write(2, ":", 1);
	ft_putnbr_fd(lex->ligne, 2);
	while (lex && lex->ligne == ligne)
	{
		write(2, "\t", 1);
		write(2, lex->code, ft_strlen(lex->code));
		lex = lex->next;
	}
	write(2, "\n", 1);
	write(2, strerr, ft_strlen(strerr));
	write(2, "\n", 1);
	free_lex();
	exit_main();
}
