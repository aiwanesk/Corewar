#include <op.h>
#include <header.h>
#include <compilateur.h>
#include <struct_lex.h>

unsigned int	rev_indian(unsigned int n)
{
	unsigned int	rev;

	rev = 0;
	rev += (n & 0xFF);
	rev <<= 8;
	rev += (n & 0xFF00) >> 8;
	rev <<= 8;
	rev += (n & 0xFF0000) >> 16;
	rev <<= 8;
	rev += (n & 0xFF000000) >> 24;
	return (rev);
}

void			compilation(t_lex *lex)
{
	unsigned int	size;
	t_lex			*ltmp;

	ltmp = lex;
	size = 0;
	while (ltmp)
	{
		if (ltmp->type == CMD)
			cmd_use(ltmp->code);
		else if (ltmp->type == LABEL)
			lab_new(ltmp, size);
		else if (ltmp->type == OPCODE)
			size += byt_size(ltmp);
		ltmp = ltmp->next;
	}
	ltmp = lex;
	while (ltmp)
	{
		if (ltmp->type == OPCODE)
			byt_new(ltmp);
		ltmp = ltmp->next;
	}
	head_size(size);
	write_bytecode(size);
}
