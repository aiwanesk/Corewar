#ifndef CPU_H
# define CPU_H

# include "../libs/libft/include/libft.h"

#include <stdio.h> //for debug purpose only

#define CGREEN "\033[32m"
#define CRED "\033[31m"
#define CWHITE  "\033[37m"

typedef struct		s_process{
	int				pc;
	int				live;
	char			*name;
}					t_process;

void				apply_function(t_process **process);

void				apply_live(t_process **process);

#endif
