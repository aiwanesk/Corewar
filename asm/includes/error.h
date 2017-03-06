#ifndef ERROR_H
# define ERROR_H

# include <struct_lex.h>

/*
** error.c
*/
char			*err_name(char *namefile);
void			err_print_pos(int pos);
void			error(t_lex *lex, int pos, char *strerr);

#endif
