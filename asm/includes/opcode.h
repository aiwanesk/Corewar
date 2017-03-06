#ifndef OPCODE_H
# define OPCODE_H

typedef struct		s_op
{
	char			code;
	char			labelsize;
	char			nbrarg;
	unsigned int	hash;
	char			arg[3];
}					t_op;

/*
** opcode.c
*/
t_op				get_by_name(char *name);
t_op				get_by_code(char code);

#endif
