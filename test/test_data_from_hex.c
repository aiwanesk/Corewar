#include "test.h"

void test_data_from_hex(){
	int i = 0;
	char *leaks;
	for (; i < 256; i++){
		//if (i == 104 || i == 100 || i == 255)
		//printf("%s\n", get_data_from_hex(i).val);
		leaks = strdup(get_data_from_hex(i).val);
		int j;
		printf("%s = %d = ", leaks, i);
		for (j = 0; j < 8; j+=2)
			printf("%d ", int_to_read(leaks, j, 0));
		printf("\n");
	}
}
