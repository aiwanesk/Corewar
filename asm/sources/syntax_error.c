#include <unistd.h>
#include <error.h>
#include <struct_lex.h>

void			syntax_error(t_lex *lex, int pos, char *strerr)
{
	write(2, "Syntax error\n", 13);
	error(lex, pos, strerr);
}
