#ifndef LABEL_H
# define LABEL_H

# include <struct_lex.h>

# define SIZE_ARRAY 100

typedef struct		s_label
{
	unsigned int	hash;
	unsigned int	addr;
}					t_label;

typedef struct		s_lab
{
	unsigned int	libre;
	t_label			label[SIZE_ARRAY + 1];
	struct s_lab	*next;
}					t_lab;

/*
** label0.c
*/
t_lab			*lab_get(void);
void			lab_new(t_lex *lex, unsigned int size);
void			lab_free(void);

/*
** label1.c
*/
void			lab_check(t_lex *lex, unsigned int label);
t_label			label_valid(t_lex *lex, int pos, unsigned int label);

#endif
