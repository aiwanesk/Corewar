#!/bin/bash 

#gcc -Wall -Wextra -Werror -g -I includes sources/* libs/libft/libft.a;
gcc -g -I includes libs/libft/libft.a sources/apply_function.c sources/apply_live.c test/*
