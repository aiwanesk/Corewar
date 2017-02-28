#ifndef SYNTAX_ANALYSER_H
# define SYNTAX_ANALYSER_H

/*
** syntax_analyser.c
*/
void			syn_analyser(t_lex *lex);

/*
** syntax_error.c
*/
char			*syn_err_name(char *namefile);
void			syntax_error(t_lex *lex, char *strerr);

#endif
