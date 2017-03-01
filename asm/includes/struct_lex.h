#ifndef STRUCT_LEX_H
# define STRUCT_LEX_H

enum	e_Type
{
	OPCODE,
	LABEL,
	CMD
};

typedef enum e_Type		e_Type;

struct				s_lex
{
	e_Type			type;
	char			*code;
	int				ligne;
	struct s_lex	*next;
};

typedef	struct s_lex	t_lex;

/*
** struct_lex.h
*/
t_lex				*get_lex(void);
void				new_lex(char *code, e_Type type, int ligne);
void				free_lex(void);


#endif
