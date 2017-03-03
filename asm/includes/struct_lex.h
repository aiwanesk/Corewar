#ifndef STRUCT_LEX_H
# define STRUCT_LEX_H

enum	e_type
{
	OPCODE,
	LABEL,
	CMD
};

struct				s_lex
{
	enum e_type		type;
	char			*code;
	int				ligne;
	struct s_lex	*next;
};

typedef	struct s_lex	t_lex;

/*
** struct_lex.h
*/
t_lex				*get_lex(void);
void				new_lex(char *code, enum e_type type, int ligne);
void				free_lex(void);


#endif
