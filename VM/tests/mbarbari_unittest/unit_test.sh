#!/bin/bash

trash=~/trash
mkdir -p ~/trash
ERROR="\e[5m\e[1m\e[31mKO\e[39m\n"
OK="\e[1m\e[32mOK\e[39m\n"

ROOTFILE=../../
DIFF_FILE=./diff_test

TEST=" > /dev/null && printf $OK || printf $ERROR"

memory_file="../../sources/memory.c ./src_test/memory.c"

declare -a instruction=(
	"$memory_file:Test memory - print memory null :-NOTHING:exec_memory_print"
	"$memory_file:Test memory - write memory whitout buffer overflow - case array 200 :-DWRITE_MEMORY -DARRAY_CASE=200:exec_memory_wbo"
	"$memory_file:Test memory - write memory whith buffer overflow - case array 4296 - 4096 = 200 :-DWRITE_MEMORY -DARRAY_CASE=4296:exec_memory_bo"
	"$memory_file:Test memory - random write memory :-DWRITE_MEMORY_RAND -DMEMORY_MEM_SAVE=5000:exec_memory_rand"
	"$memory_file:Test memory - random write memory with BO :-DWRITE_MEMORY_RAND_BO -DMEMORY_MEM_SAVE=5000:exec_memory_rand_bo"
	"$memory_file:Test memory - random read memory with BO :-DREAD_MEMORY_RAND_BO -DMEMORY_MEM_SAVE=5000:exec_memory_read_rand_bo"
)

cflags="-g -Wno-unused-variable -Wall -Wno-unused-but-set-variable -Werror -Wextra"
libs="-I$ROOTFILE/includes -I$ROOTFILE/ -I$ROOTFILE/libs/libft/include -L$ROOTFILE/libs/libft"

IFS=""

for i in ${instruction[*]}
do
	printf "%s\n" "$i"
	IFS=":" read -ra ELEM <<< "$i"
	printf "%s " "${ELEM[1]}"
	printf "%s\n" "gcc $cflags $libs  -o ${ELEM[3]} ${ELEM[2]} ${ELEM[0]} -lft"
	#./"${ELEM[3]}" > $DIFF_FILE/"${ELEM[3]}".diff
done


	#printf "test - :"
	#printf "%s " "${ELEM[1]}"
	#printf "%s\n" "gcc $cflags $libs  -o ${ELEM[3]} ${ELEM[2]} ${ELEM[0]} -lft"
	#./"${ELEM[3]}" > $DIFF_FILE/"${ELEM[3]}".diff
#printf "Test memory - random read memory with BO "
#file=write_mem_rand_bo.diff
#file_diff=write_mem_rand_diff.diff
#exec=exec_memory_rand
#gcc $cflags $libs -DREAD_MEMORY_RAND_BO -DMEMORY_MEM_SAVE=5000 -o $exec $ROOTFILE/sources/memory.c ./src_test/memory.c -lft
#./$exec > diff_test/$file ; diff diff_test/write_mem_rand.diff diff_ok/$file > diff_test/$file_diff
#diff diff_test/$file_diff diff_ok/$file_diff && printf $OK || printf $ERROR


#mv ./exec_* $trash
