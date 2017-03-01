#ifndef TEST_H
#define TEST_H

#include "cpu.h"

#define SUCCESS 0
#define FAILURE 1

void logWriter(char *test, int success);

void test_or();
void test_and();
void test_xor();
void test_data_from_hex();

t_process create_process();

#endif
