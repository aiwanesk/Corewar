#include <unistd.h>
#include <stdlib.h>
#include <struct_lex.h>
#include <lexical_analyser.h>
#include <syntax_analyser.h>
#include <label.h>
#include <compilateur.h>
#include <error.h>

static char		**st_get(void)
{
	static char		*str = 0x00;

	return (&str);
}

int				main(int ac, char **av)
{
	char	**code;

	code = st_get();
	if (ac != 2)
	{
		write(1, "asm <file>.s\n", 13);
		return (1);
	}
	*code = bufferise(av[1]);
	if (*code == 0x00)
		return (1);
	err_name(av[1]);
	syn_analyser(lex_analyser(*code));
	compilation(get_lex());
	free(*code);
	free_lex();
	lab_free();
	return (0);
}

void			exit_main(void)
{
	char	**code;

	code = st_get();
	free(*code);
	lab_free();
	free_lex();
	exit(2);
}
