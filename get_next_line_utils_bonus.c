#include "get_next_line_bonus.h"

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
		(*list)->buf = buf;
		(*list)->next = NULL;
		return ;
	}
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->buf = buf;
	new_node->next = NULL;
	last->next = new_node;
}

void	ft_newlist(t_list **list, int fd)
{
	char	*buf;
	size_t	read_tracker;

	while (!ft_founded_nl(*list))
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		read_tracker = read(fd, buf, BUFFER_SIZE);
		if (!read_tracker)
		{
			free(buf);
			return ;
		}
		buf[read_tracker] = '\0';
		ft_append(list, buf);
	}
}
