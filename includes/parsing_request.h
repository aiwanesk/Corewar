#ifndef PARSING_REQUEST_H
# define PARSING_REQUEST_H

#include "../libs/libft/include/libft.h"

void			parse_request(char *binary);
				int get_op_code(char a, char b);

void			exit_error(char *s);

#endif
