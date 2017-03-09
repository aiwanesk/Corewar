#ifndef COMPILATEUR_H
# define COMPILATEUR_H

# include <struct_lex.h>
# include <label.h>
# include <bytecode.h>

/*
** buffer.c
*/
char			*bufferise(char *namefile);

/*
** main.c
*/
void			exit_main(void);

/*
** djb2.c
*/
unsigned int	djb2(char *str);

/*
** compilation.c
*/
unsigned int	rev_indian(unsigned int n);
void			compilation(t_lex *lex);

/*
** cmd.c
*/
void			cmd_use(char *code);

#endif
