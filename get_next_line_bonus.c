/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:21:35 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/05 16:53:04 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_clean(t_list **list)
{
	
}

size_t	ft_len_to_nl(t_list *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (list)
	{
		j = 0;
		while (list->buf[j])
		{
			if (list->buf[j] == '\n')
				return (i);
			i++;
			j++;
		}
		list = list->next;
	}
	return (i);
}

char	*ft_find_line(t_list *list)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = ft_len_to_nl(list);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (list)
	{
		j = 0;
		while (list->buf[j])
		{
			line[i++] = list->buf[j];
			if (list->buf[j++] == '\n')
			{
				line[i] = '\0';
				return (line);
			}
		}
		list = list->next;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*list[FD_MAX] = {NULL};
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ft_newlist(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	line = ft_find_line(list[fd]);
	ft_clean(&list[fd]);
	return (line);
}
