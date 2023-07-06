/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:10:53 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/06 19:29:11 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_MAX 257
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}t_list;

void	ft_newlist(t_list **list, int fd);
char	*ft_find_line(t_list *list);
void	ft_clean(t_list **list);
t_list	*ft_lst(t_list *list);
char	*get_next_line(int fd);
void	ft_dealloc(t_list **list, t_list *clean_node);
size_t	ft_len_to_nl(t_list *list);
int		ft_founded_nl(t_list *list);
void	ft_append(t_list **list, char *buf);
void	ft_strcpy(char *dest, const char *src);

#endif