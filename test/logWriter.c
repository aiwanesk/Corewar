#include "test.h"

void		logWriter(char *name, int success){
	if (success)
		printf("%s", CGREEN);
	else
		printf("%s", CRED);
	printf("%s\n%s", name, CWHITE);
}
