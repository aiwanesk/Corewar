#ifndef SYNTAX_ANALYSER_H
# define SYNTAX_ANALYSER_H

# include <opcode.h>
# include <struct_lex.h>

/*
** syntax_analyser.c
*/
void			syn_analyser(t_lex *lex);

/*
** syntax_error.c
*/
char			*syn_err_name(char *namefile);
void			syntax_error(t_lex *lex, int pos, char *strerr);

/*
** syntax_argument.c
*/
void			syn_check_arg(t_lex *lex, t_op op, int pos);

#endif
