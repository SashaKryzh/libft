
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *st_buff[10000];
	char		*buff;
	int			ret;

	if (ft_strchr(st_buff[fd], '\n'))
		return ()
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ft_strchr(buff, '\n'))
	}
}
