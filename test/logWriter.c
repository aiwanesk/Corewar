#include "test.h"

void		logWriter(char *name, int success){
	if (success == SUCCESS)
		printf("%s", CGREEN);
	else
		printf("%s", CRED);
	printf("%s\n%s", name, CWHITE);
}
