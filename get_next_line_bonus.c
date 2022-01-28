/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:12:32 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/06 20:10:51 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_get_new_chars(int fd, char *saved_lines, char *buffer)
{
	int	chars_counter;

	if (!buffer)
		return (NULL);
	chars_counter = 1;
	while (!ft_strchr(saved_lines, '\n') && chars_counter != 0)
	{
		chars_counter = read(fd, buffer, BUFFER_SIZE);
		if (chars_counter == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[chars_counter] = '\0';
		saved_lines = ft_strjoin(saved_lines, buffer);
	}
	return (saved_lines);
}

char	*ft_get_line(char *saved_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved_line)
		return (NULL);
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char ) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
	{
		line[i] = saved_line[i];
		i++;
	}
	if (saved_line[i] == '\n')
	{
		line[i] = saved_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *saved_line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	if (!saved_line[i])
	{
		free(saved_line);
		return (NULL);
	}
	new_line = (char *) malloc(sizeof(char) * (ft_strlen(saved_line) - i + 1));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (saved_line[i])
		new_line[j++] = saved_line[i++];
	new_line[j] = '\0';
	free(saved_line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	static char	*saved_lines[OPEN_MAX];

	if (read(fd, buff, 0) != 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!saved_lines[fd])
	{
		saved_lines[fd] = (char *)malloc(sizeof (char) * 1);
		if (!saved_lines[fd])
			return (NULL);
		saved_lines[fd][0] = '\0';
	}
	saved_lines[fd] = ft_get_new_chars(fd, saved_lines[fd], buff);
	if (!saved_lines[fd])
		return (NULL);
	line = ft_get_line(saved_lines[fd]);
	saved_lines[fd] = ft_save(saved_lines[fd]);
	if (line[0])
		return (line);
	free(line);
	return (NULL);
}
