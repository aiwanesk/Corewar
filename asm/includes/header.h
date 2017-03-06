#ifndef HEADER_H
# define HEADER_H

enum	e_data
{
	NAME,
	COMMENT
};

/*
** header.h
*/
void			head_data(enum e_data data, char *code);
void			head_size(int size);
void			write_header(int fd);

#endif
