#ifndef TEST_H
#define TEST_H

#include "cpu.h"

#define SUCCESS 0
#define FAILURE 1

void logWriter(char *test, int success);

void test_or();

t_process create_process();

#endif
