#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<math.h>

# define BUFFER_SIZE 3

typedef struct s_list
{
	float			x;
    float           y;
    float           z;
	void			*next;
}					t_list;

int     get_next_line(int fd, char **line);
char    *ft_strjoin_free(char *s1, char *s2);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);
void    *ft_memcpy(void *dst, const void *src, size_t n);
char    **ft_split(char *str);

#endif