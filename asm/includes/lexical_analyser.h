#ifndef LEXICAL_ANALYSER_H
# define LEXICAL_ANALYSER_H

# include <struct_lex.h>

/*
** lexical_analyser.c
*/
t_lex			*lex_analyser(char *src);

/*
** lex_cmd.c
*/
unsigned int	lex_is_cmd(char *str, unsigned int size);
void			lex_add_cmd(char *str, unsigned int *pos, int ligne);

/*
** lex_label.c
*/
void			lex_add_label(char *str, unsigned int *pos, int *ligne);

/*
** lex_opcode.c
*/
void			lex_add_opcode(char *str, unsigned int *pos, int ligne);

#endif
