/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:15:45 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/06 23:41:27 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	char	*res_iter;
	int		res_len;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	res_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	result = (char *)malloc(res_len * sizeof(char));
	if (!result)
		return (NULL);
	res_iter = result;
	i = -1;
	if (str1)
	{
		while (str1[++i])
			*res_iter++ = str1[i];
	}
	while (*str2)
		*res_iter++ = *str2++;
	*res_iter = 0x00;
	free(str1);
	return (result);
}

char	*ft_strchr(char *src, int c)
{
	char	chr_c;

	if (!src)
		return (NULL);
	chr_c = (char) c;
	while (*src != chr_c)
	{
		if (!*src)
			return (NULL);
		src++;
	}
	return ((char *)src);
}
