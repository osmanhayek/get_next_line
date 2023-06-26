#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void  create_res(char **res, int fd);
char  *clean_res(char *res);
char  *get_next_line(int fd);
size_t  ft_strlen(char *str);
char  *ft_append(char *s1, char *s2);
size_t  founded_next_line(char *res);
size_t  len_to_next_line(char *str);
char  *find_line(char *res);
void  ft_strcpy(char *s1, char *s2);

#endif