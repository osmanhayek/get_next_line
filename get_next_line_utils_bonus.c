/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:02:57 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/06 19:34:23 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

t_list	*ft_lst(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	ft_founded_nl(t_list *list)
{
	t_list	*last;
	size_t	i;

	last = ft_lst(list);
	if (!last)
		return (0);
	i = 0;
	while (last->buf[i])
	{
		if (last->buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_append(t_list **list, char *buf)
{
	t_list	*last;
	t_list	*new_node;

	last = ft_lst(*list);
	if (!last)
	{
		*list = (t_list *)malloc(sizeof(t_list));
		if (!*list)
			return ;
		ft_strcpy((*list)->buf, buf);
		(*list)->next = NULL;
		return ;
	}
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	ft_strcpy(new_node->buf, buf);
	new_node->next = NULL;
	last->next = new_node;
}

void	ft_newlist(t_list **list, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	size_t	read_tracker;

	while (!ft_founded_nl(*list))
	{
		read_tracker = read(fd, buf, BUFFER_SIZE);
		if (!read_tracker)
			return ;
		buf[read_tracker] = '\0';
		ft_append(list, buf);
	}
}
