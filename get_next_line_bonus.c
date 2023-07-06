/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:21:35 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/06 19:34:09 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_dealloc(t_list **list, t_list *clean_node)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->buf[0])
		*list = clean_node;
	else
		free(clean_node);
}

void	ft_clean(t_list **list)
{
	t_list	*new_list;
	t_list	*last;
	char	new_buf[BUFFER_SIZE + 1];
	size_t	i;
	size_t	k;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return ;
	last = ft_lst(*list);
	if (!last)
		return ;
	i = 0;
	k = 0;
	while (last->buf[i] && last->buf[i] != '\n')
		i++;
	while (last->buf[i] && last->buf[++i])
		new_buf[k++] = last->buf[i];
	new_buf[k] = '\0';
	ft_strcpy(new_list->buf, new_buf);
	new_list->next = NULL;
	ft_dealloc(list, new_list);
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
				return (i + 1);
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
	t_list			*tmp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > FD_MAX)
	{
		if (fd > 0 && fd <= FD_MAX)
		{
			while (list[fd])
			{
				tmp = list[fd]->next;
				free(list[fd]);
				list[fd] = tmp;
			}
			list[fd] = NULL;
		}
		return (NULL);
	}
	ft_newlist(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	line = ft_find_line(list[fd]);
	ft_clean(&list[fd]);
	return (line);
}
