#include <libft.h>
#include <op.h>
#include <header.h>
#include <compilateur.h>

void			cmd_use(char *code)
{
	unsigned int	i;
	unsigned int	hash;

	i = 0;
	while (!ft_isspace(code[i]))
		++i;
	code[i] = '\0';
	hash = djb2(code);
	code[i] = ' ';
	if (hash == djb2(NAME_CMD_STRING))
		head_data(NAME, code);
	else if (hash == djb2(COMMENT_CMD_STRING))
		head_data(COMMENT, code);
}
