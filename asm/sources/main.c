#include <unistd.h>
#include <stdlib.h>
#include <lexical_analyser.h>
#include <compilateur.h>

static char		**st_get(void)
{
	static char		*str = 0x00;

	return (&str);
}

int			main(int ac, char **av)
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
	lex_analyser(*code);
	free(*code);
	return (0);
}

void		exit_main(void)
{
	char	**code;

	code = st_get();
	free(*code);
	free_lex();
	exit(2);
}
