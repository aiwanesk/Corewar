#include "../includes/parsing_request.h"
#include <stdio.h>

int			main(){
	int i = 0;
	char mem[MEM_SIZE];

	for (; i < MEM_SIZE; i++){
		mem[i] = i;
//		printf("%c\n", mem[i]);
	}
	for (i = 0; i < MEM_SIZE; i++)
		parse_request(i, mem);
	return 0;
}
