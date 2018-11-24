/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:56:11 by okryzhan          #+#    #+#             */
/*   Updated: 2018/11/03 15:56:13 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static t_gnl	*ft_new_fd(int fd, t_gnl *next)
// {
// 	t_gnl	*tmp;

// 	tmp = (t_gnl *)malloc(sizeof(t_gnl));
// 	tmp->str = NULL;
// 	tmp->fd = fd;
// 	tmp->next = next;
// 	return (tmp);
// }

// static char		*ft_update_str(int path, char *st_buff, char *buff, size_t len)
// {
// 	char *tmp;

// 	tmp = st_buff;
// 	if (path == 1)
// 		st_buff = ft_strjoin(st_buff, buff);
// 	else if (path == 2)
// 		st_buff = ft_strdup(&st_buff[len + 1]);
// 	free(tmp);
// 	return (st_buff);
// }

// static int		ft_return_line(int ret, t_gnl *elem, char **line)
// {
// 	size_t	len;

// 	len = 0;
// 	if (ret < 0)
// 		return (-1);
// 	if (ret == 0 && elem->str == NULL)
// 		return (0);
// 	while (elem->str[len] != '\n' && elem->str[len] != '\0')
// 		len++;
// 	if (elem->str[len] == '\n')
// 	{
// 		*line = len ? ft_strsub(elem->str, 0, len) : ft_strnew(0);
// 		elem->str = ft_update_str(2, elem->str, NULL, len);
// 		if (elem->str[0] == '\0')
// 			ft_strdel(&elem->str);
// 	}
// 	else
// 	{
// 		*line = len ? ft_strsub(elem->str, 0, len) : ft_strnew(0);
// 		ft_strdel(&elem->str);
// 		if (ret == 0)
// 			return (0);
// 	}
// 	return (1);
// }

// int				get_next_line(const int fd, char **line)
// {
// 	static t_gnl	*list;
// 	t_gnl			*elem;
// 	char			buff[BUFF_SIZE + 1];
// 	int				ret;

// 	if (fd < 0 || line == NULL)
// 		return (-1);
// 	elem = list;
// 	while (elem && elem->fd != fd)
// 		elem = elem->next;
// 	if (elem == NULL)
// 	{
// 		elem = ft_new_fd(fd, list);
// 		list = elem;
// 	}
// 	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		buff[ret] = '\0';
// 		elem->str = elem->str ? elem->str : ft_strnew(0);
// 		elem->str = ft_update_str(1, elem->str, buff, 0);
// 		if (ft_strrchr(buff, '\n'))
// 			break ;
// 	}
// 	return (ft_return_line(ret, elem, line));
// }

size_t	ft_linelen(char *str, int *end)
{
	size_t len;

	len = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			*end = 1;
			return (len);
		}
		len++;
		str++;
	}
	return (len);
}

t_file	*ft_find_fd(t_file **file, const int fd, char **line)
{
	t_file	*tmp;

	tmp = *file;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			*line = ft_strnew(0);
			return (tmp);
		}
		tmp = tmp->next;
	}
	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
	{
		free(tmp);
		return (NULL);
	}
	tmp->next = *file;
	tmp->fd = fd;
	tmp->count = 0;
	*file = tmp;
	*line = ft_strnew(0);
	return (tmp);
}

int		ft_rewrite(t_file *curr, char **line, int *end)
{
	size_t	len;
	char	*prev_line;

	len = ft_linelen(curr->buff + curr->count, end);
	prev_line = *line;
	if (!(*line = (char *)malloc(len + ft_strlen(*line) + 1)))
	{
		free(prev_line);
		return (-1);
	}
	ft_strcpy(*line, prev_line);
	ft_strncat(*line, curr->buff + curr->count, len);
	if (curr->count >= BUFF_SIZE && (*end != 0 || *end != 1))
		*end = -1;
	curr->count += len + 1;
	free(prev_line);
	return (0);
}

int		ft_write_line(t_file *curr, char **line, int *end)
{
	ssize_t		tmp;

	tmp = 1;
	if (curr->count == 0 || curr->count >= BUFF_SIZE ||
			(curr->buff)[curr->count - 1] == '\0')
	{
		if (!(tmp = read(curr->fd, curr->buff, BUFF_SIZE)))
		{
			*end = 0;
			return (0);
		}
		(curr->buff)[tmp] = '\0';
		curr->count = 0;
	}
	if (tmp < 0)
		return (-1);
	if (ft_rewrite(curr, line, end) == -1)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*list;
	t_file			*curr;
	int				end;

	if (fd < 0 || !line)
		return (-1);
	if (!(curr = ft_find_fd(&list, fd, line)))
		return (-1);
	end = -1;
	while (end == -1)
	{
		if (ft_write_line(curr, line, &end) == -1)
			return (-1);
	}
	return (end || (**line != '\0'));
}