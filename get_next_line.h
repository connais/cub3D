#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFFER_SIZE 256

char	*get_next_line(int fd);
char	*free_all(char **buffer, char **line, char **res);
char	*read_buff(char *buffer, int fd);
char	*hydrate_line(char *src);
char	*crop_line(char *src);
size_t	ft_strlen_n(char *str);
size_t	ft_strlen_gnl(const char *str);
char	*free_null(char *ptr);
int	    ft_isline(char *str);
char	*ft_realloc_cat(char *src, char *dst);

#endif