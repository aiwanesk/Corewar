#include <unistd.h>
#include <stdlib.h>
#include <compilateur.h>

int			main(int ac, char **av)
{
	char	*code;

	if (ac != 2)
	{
		write(1, "asm <file>.s\n", 13);
		return (1);
	}
	code = bufferise(av[1]);
	free(code);
	return (0);
}
