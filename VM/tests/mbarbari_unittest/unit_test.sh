#!/bin/bash

trash=~/trash
mkdir -p ~/trash
ERROR="\e[5m\e[1m\e[31mKO\e[39m\n"
OK="\e[1m\e[32mOK\e[39m\n"

ROOTFILE=../../../
DIFF_FILE=./diff_test
DIFF_OK=./diff_ok

TEST=" > /dev/null && printf $OK || printf $ERROR"
EXEC_DIR="./exec_test/"

source_file="../../sources/memory.c "
source_file+="../../sources/options.c "
source_file+="../../sources/process.c "
source_file+="../../sources/random.c "
source_file+="../../sources/core.c "
source_file+="../../sources/tools.c "

memory_file="$source_file ./src_test/memory.c"
options_file="$source_file ./src_test/options.c"
init_memory_file="$source_file ./src_test/init_memory.c"

declare -a instruction=(
	"$memory_file:Test memory - print memory null::exec_memory_print"
	"$memory_file:Test memory - write memory whitout buffer overflow - case array 200:-DWRITE_MEMORY -DARRAY_CASE=200:exec_memory_wbo"
	"$memory_file:Test memory - write memory whith buffer overflow - case array 4296 - 4096 = 200:-DWRITE_MEMORY -DARRAY_CASE=4296:exec_memory_bo"
	"$memory_file:Test memory - random write memory:-DWRITE_MEMORY_RAND -DMEMORY_MEM_SAVE=4096:exec_memory_rand"
	"$memory_file:Test memory - random write memory with BO:-DWRITE_MEMORY_RAND_BO -DMEMORY_MEM_SAVE=5000:exec_memory_rand_bo"
	"$memory_file:Test memory - random read memory without BO:-DREAD_MEMORY_RAND -DMEMORY_END_READ=4096 -DMEMORY_MEM_SAVE=4096:exec_memory_read_rand_wbo"
	"$memory_file:Test memory - random read memory with BO:-DREAD_MEMORY_RAND -DMEMORY_START_READ=4096 -DMEMORY_END_READ=8192 -DMEMORY_MEM_SAVE=4096:exec_memory_read_rand_bo"
	"$memory_file:Test memory - cpy memory:-DWRITE_MEMORY_RAND -DCPY_MEMORY_RAND -DMEMORY_MEM_SAVE=4096:exec_memory_cpy_rand"
	"$options_file:Test options - normal test \"-dump 200 -n 4 champion.cor champion1.cor ... champion3.cor\"::exec_options_normaltest"
	"$options_file:Test options - process test \"-dump 200 -n 4 champion.cor champion1.cor ... champion3.cor\":-DPROCESS:exec_options_processtest"
	"$init_memory_file:Test init Memory - Read core file and set memory\"-dump 200 -n 2 0.t.core.cor 0.t.core.cor\"::exec_initmemory"
)

cflags="-g -Wno-unused-variable -Wall -Wno-unused-but-set-variable -Werror -Wextra"
libs="-I$ROOTFILE/VM/includes -I$ROOTFILE/core -I$ROOTFILE/libs/libft/include -L$ROOTFILE/libs/libft"

IFS=""

for i in ${instruction[*]}
do
	mkdir -p $EXEC_DIR
	IFS=":" read -ra ELEM <<< "$i"
	eval "gcc $cflags $libs  -o $EXEC_DIR/${ELEM[3]} ${ELEM[2]} ${ELEM[0]} -lft"
	$EXEC_DIR/"${ELEM[3]}" > $DIFF_FILE/"${ELEM[3]}".diff
	printf "%s " "${ELEM[1]}"
	diff $DIFF_FILE/"${ELEM[3]}".diff $DIFF_OK/"${ELEM[3]}".diff > /dev/null && printf $OK || printf $ERROR
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
