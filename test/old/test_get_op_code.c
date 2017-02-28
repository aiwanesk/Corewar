#include "../includes/parsing_request.h"
#include <stdio.h>

void test_get_op_code(){
	if (12 ==  get_op_code('0', 'c')){
	if (8 ==  get_op_code('0', '8'))
	if (4 ==  get_op_code('0', '4'))
	if (3 ==  get_op_code('0', '3'))
	if (2 ==  get_op_code('0', '2'))
	if (1 ==  get_op_code('0', '1'))
	if (16 ==  get_op_code('1', '0'))
		printf("Success get_op_code\n");
	}
	else
		printf("Fail get_op_code\n");
}
