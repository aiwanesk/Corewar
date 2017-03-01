#!/bin/bash 

gcc -g -I includes sources/*.c sources/app/*.c test/*.c -I libs/libft/include libs/libft/libft.a
