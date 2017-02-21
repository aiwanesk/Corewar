#ifndef TEST_H
#define TEST_H

#include "cpu.h"

#define SUCCESS 0
#define FAILURE 1

void logWriter(char *test, int success);

void launcher_test_alive();
void launcher_test_ld();

#endif
