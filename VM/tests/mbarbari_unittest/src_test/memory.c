#include "core.h"
#include "op.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	memory_write(uint32_t memory[], uint32_t addr, uint32_t val)
 {
	#ifdef ARRAY_CASE
		write_memory(memory, ARRAY_CASE, 55); //Donne 37 hexa
	#else
		write_memory(memory, addr, val);
	#endif
	(void)addr;
	(void)val;
}

void	memory_rand(uint32_t memory[])
{
	int			i;
	uint32_t	addr;

	i = 0;
	addr = 0;
	#ifdef MEMORY_MEM_SAVE
		while (i < MEMORY_MEM_SAVE)
		{
			addr = rand() % MEMORY_MEM_SAVE;
			write_memory(memory, addr, (uint32_t)(rand() % 99));
			++i;
		}
	#else
		(void)memory;
		dprintf(1, "MEMORY_MEM_SAVE dont exists");
	#endif
}

void	memory_read(uint32_t memory[])
{
	int			i;
	uint32_t	addr;

	#ifdef MEMORY_START_READ
	i = MEMORY_START_READ;;
	#else
	i = 0;
	#endif
	memory_rand(memory);
	#ifdef MEMORY_END_READ
		while (i < MEMORY_END_READ)
		{
			if (i > 0 && i % MEM_SIZE > 0 && (i % 64) == 0)
				write(1, "\n", 1);
			//addr = rand() % MEMORY_END_READ;
			dprintf(1, "%.2X ", read_memory(memory, i));
			++i;
		}
	#else
		(void)memory;
		dprintf(1, "MEMORY_END_READ dont exists");
	#endif
}

int		main(void)
{
	int				i;
	int				print;
	uint32_t		memory[MEM_SIZE];
	uint32_t		cpy[MEM_SIZE];

	print = 1;
	bzero(memory, sizeof(uint32_t) * MEM_SIZE);
	#ifdef WRITE_MEMORY
		memory_write(memory, 0, 0);
	#elif WRITE_MEMORY_RAND
		memory_rand(memory);
	#elif WRITE_MEMORY_RAND_BO
		memory_rand(memory);
		memory_write(memory, 7000, 'A');
	#elif READ_MEMORY_RAND
		memory_rand(memory);
		memory_read(memory);
		print = 0;
	#elif CPY_MEMORY_RAND
		memory_rand(memory);
		memory_rand(cpy);
		cpy_memory(cpy, memory);
		print_memory(cpy);
		print = 0;
	#endif
	if (print == 1)
		print_memory(memory);
	return (0);
}
