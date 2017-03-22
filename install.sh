#!/bin/sh
make -C ./libs/libft
make -C ./VM/
make -C ./asm/
COREWAR=$PWD"/VM/"
