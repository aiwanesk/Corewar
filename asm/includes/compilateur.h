#ifndef COMPILATEUR_H
# define COMPILATEUR_H

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

#endif
