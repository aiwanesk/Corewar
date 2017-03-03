#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <op.h>
#include <libft.h>
#include <compilateur.h>

int			main(void)
{
	int		status;
	int		i;
	char	*str;

	status = 0;

	/*
	** Check extensions file
	*/
	char		*filename[] = {
		".s",
		"test.asm",
		"test.as",
		"test.sa",
		".sa",
		".ms",
		"s",
		0x00
	};
	i = 0;
	while (filename[i]){
		str = bufferise(filename[i]);
		if (str != 0x00){
			status = 1;
			free(str);
		}
		++i;
	}

	/*
	** Check file or path don't exist
	*/
	str = bufferise("nofile.s");
	if (str != 0x00){
		status = 1;
		free(str);
	}
	str = bufferise("tmp/nofile.s");
	if (str != 0x00){
		status = 1;
		free(str);
	}

	/*
	** Check empty file
	*/
	int		fd;

	fd = open("emptyfile.s", O_CREAT, 00600);
	if (fd != -1){
		close(fd);
		str = bufferise("emptyfile.s");
		if (str == 0x00){
			status = 1;
		}else{
			free(str);
		}
		remove("emptyfile.s");
	}else{
		status = 2;
	}

	/*
	** Check data
	*/
	char		*data[] = {
		"\0",
		"Ceci est\n #commentaire un test\n de data\n\0",
		"AND 1234567890 + 0987654321\0",
		"woej oiewjfoqiwejfoiewjf owiejfoi weoifj oiwejfoijew ifqowejf \0",
		"           \0",
		".source: toto\0",
		"\n\n\n\n.data:\n30\n686434\n\n98\n\0",
		0x00
	};
	i = 0;
	while (data[i]){
		fd = open("file.s", O_CREAT | O_WRONLY, 00600);
		if (fd != -1){
			dprintf(1, "[%s]\n", data[i]);
			write(fd, data[i], ft_strlen(data[i]));
			close(fd);
			str = bufferise("file.s");
			if (str == 0x00){
				status = 1;
			}else{
				if (ft_strcmp(str, data[i]) != 0)
					status = 1;
				free(str);
			}
			remove("file.s");
		}else{
			status = 2;
		}
		++i;
	}

	return (status);
}
