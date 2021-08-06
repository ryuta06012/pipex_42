#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include "stdlib.h"
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		get_next_line(const int fd, char **line);
char	*get_save_line(char *mem);
char	*get_line(char *mem);
char	*line_get(char *mem, int fd, int *read_value);
int		get_next_line(int fd, char **line);
size_t	new_line_strlen(const char *line);
int		new_line_return(char *mem);
size_t	get_strlen (const char *str);
char	*get_strjoin(char *s1, char const *s2);

#endif