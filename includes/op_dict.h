#ifndef OP_DICT_H
# define OP_DICT_H

typedef struct s_dict		t_dict;

struct						s_dict{
	int						op_code;
	int						cycle;
};

struct s_dict						*init_dict(void);//pas terrible une idee de meilleur design
int									get_cycle(int op_code);


#endif
