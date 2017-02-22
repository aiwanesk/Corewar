#include "virtual_machine.h"
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

	i = 0;
	#ifdef MEMORY_MEM_SAVE
		while (i < MEMORY_MEM_SAVE)
		{
			addr = rand() % MEMORY_MEM_SAVE;
			dprintf(1, "%2X ", read_memory(memory, addr));
			++i;
		}
	#else
		(void)memory;
		dprintf(1, "MEMORY_MEM_SAVE dont exists");
	#endif
}

int		main(void)
{
	int				i;
	uint32_t		memory[MEM_SIZE];

	bzero(memory, sizeof(uint32_t) * MEM_SIZE);
	#ifdef WRITE_MEMORY
		memory_write(memory, 0, 0);
		print_memory(memory);
	#elif WRITE_MEMORY_RAND
		memory_rand(memory);
	#elif WRITE_MEMORY_RAND_BO
		memory_rand(memory);
		memory_write(memory, 7000, 'A');
	#elif READ_MEMORY_RAND
		memory_rand(memory);
		memory_read(memory);
	#endif
	print_memory(memory);
	return (0);
}
