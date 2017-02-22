#!/bin/sh

PWD=$(pwd)
PATHCHECK=$PWD/unitest/

DEBUGCOMP=$PWD/compilation.log
DEBUGCHECK=$PWD/check.log

TEST=(
"test_buffer.c"
)

SRC=(
"buffer.c"
)

SRCPATH=$PWD/sources/

FLAGS="-Wall -Werror -Wextra -I./includes/ -I../libs/libft/include/ -I../core/"

LIBS=(
"../libs/libft/libft.a"
)

echo -e "=== Check dependance ==="
for index in "${LIBS[@]}"
do
	if [ ! -f $index ];then
		echo -en "Compiling $(basename $index) ..."
		make -C $(dirname $index)/ >/dev/null
		if [ $? == 0 ];then
			echo -en "\b\b\b"
			echo -e "\033[1;32mDONE\033[0m"
		else
			echo -en "\b\b\b"
			echo -e "\033[1;31mFAIL\033[0m"
			exit 0
		fi
	else
		echo -e "$(basename $index) \033[1;32mOK\033[0m"
	fi
done

echo -e "\n=== Check ==="
rm -f $DEBUGCOMP
rm -f $DEBUGCHECK
for main in "${TEST[@]}"
do
	if [ -f $PATHCHECK$main ];then
		echo -en "$main ..."
		gcc $FLAGS $PATHCHECK/$main $SRCPATH$SRC $LIBS -o $PATHCHECK/a.out >>$DEBUGCOMP 2>&1
		if [ $? == 0 ];then
			cd $PATHCHECK
			./a.out >$DEBUGCHECK 2>&1
			ret=$?
			if [ $ret == 0 ];then
				echo -en "\b\b\b"
				echo -e "\033[1;32mGOOD\033[0m\n"
			elif [ $ret == 2 ];then
				echo -en "\b\b\b"
				echo -e "\033[1;33mABORT\033[0m\n"
			else
				echo -en "\b\b\b"
				echo -e "\033[1;31mFAIL\033[0m\n"
			fi
			cd $PWD
			rm -f $PATHCHECK/a.out
		else
			echo -en "\b\b\b"
			echo -e "\033[1;31mFAIL COMPILATION\033[0m\n"
		fi
	fi
done
