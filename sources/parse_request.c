#include "../includes/parsing_request.h"

void			parse_request(uint32_t pc_position, char memory[MEM_SIZE])
{
	int		op_code;

	op_code = memory[pc_position];
	//if ((op_code = translate_op_code(read_op_code(pc_position, memory))) <= 0)
	//	exit_error("invalid op code");
	//printf("%d\n", op_code);
}
