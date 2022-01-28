/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:09:12 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/06 21:22:29 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *src, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_new_chars(int fd, char *saved_lines, char *buffer);
char	*ft_get_line(char *saved_line);
char	*ft_save(char *saved_line);
char	*get_next_line(int fd);
#endif
