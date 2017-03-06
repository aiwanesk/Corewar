#include <op.h>
#include <opcode.h>
#include <compilateur.h>

static void		st_init(t_op *op)
{
	op[0].hash = djb2("live");
	op[1].hash = djb2("ld");
	op[2].hash = djb2("st");
	op[3].hash = djb2("add");
	op[4].hash = djb2("sub");
	op[5].hash = djb2("and");
	op[6].hash = djb2("or");
	op[7].hash = djb2("xor");
	op[8].hash = djb2("zjmp");
	op[9].hash = djb2("ldi");
	op[10].hash = djb2("sti");
	op[11].hash = djb2("fork");
	op[12].hash = djb2("lld");
	op[13].hash = djb2("lldi");
	op[14].hash = djb2("lfork");
	op[15].hash = djb2("aff");
}

static t_op		*st_get(void)
{
	static t_op		op[17] = {
		{0x01, 4, 1, 0, {T_DIR, 0, 0}},
		{0x02, 4, 2, 0, {T_DIR | T_IND, T_REG, 0}},
		{0x03, 0, 2, 0, {T_REG, T_IND | T_REG, 0}},
		{0x04, 0, 3, 0, {T_REG, T_REG, T_REG | T_FORCE}},
		{0x05, 0, 3, 0, {T_REG, T_REG, T_REG | T_FORCE}},
		{0x06, 4, 3, 0, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}},
		{0x07, 4, 3, 0, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}},
		{0x08, 4, 3, 0, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}},
		{0x09, 2, 1, 0, {T_DIR, 0, 0}},
		{0x0A, 2, 3, 0, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
		{0x0B, 2, 3, 0, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}},
		{0x0C, 2, 1, 0, {T_DIR, 0, 0}},
		{0x0D, 4, 2, 0, {T_DIR | T_IND, T_REG, 0}},
		{0x0E, 2, 3, 0, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
		{0x0F, 2, 1, 0, {T_DIR, 0, 0}},
		{0x10, 0, 1, 0, {T_REG | T_FORCE, 0, 0}},
		{0x00, 0, 0, 0, {0, 0, 0}}
	};

	if (op[0].hash == 0)
		st_init(op);
	return (op);
}

t_op			get_by_name(char *name)
{
	unsigned int	i;
	unsigned int	namehash;
	t_op			*opcode;

	i = 0;
	opcode = st_get();
	namehash = djb2(name);
	while (opcode[i].code != 0x00)
	{
		if (opcode[i].hash == namehash)
			return (opcode[i]);
		++i;
	}
	return (opcode[16]);
}

t_op			get_by_code(char code)
{
	unsigned int	i;
	t_op			*opcode;

	i = 0;
	opcode = st_get();
	while (opcode[i].code != 0x00)
	{
		if (opcode[i].code == code)
			return (opcode[i]);
		++i;
	}
	return (opcode[16]);
}
