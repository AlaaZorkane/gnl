/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:22:57 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/08 22:14:44 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ret;

	ret = 0;
	index = 0;
	c = (unsigned char)c;
	while (1)
	{
		if (s[index] == c)
		{
			ret = (char *)&s[index];
			return (ret);
		}
		if (s[index] == '\0')
			return (NULL);
		index++;
	}
	return (ret);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, s1));
}

char	*ft_strcat(char *dest, const char *src)
{
	int index;
	int destlen;

	index = 0;
	destlen = ft_strlen(dest);
	while (src[index] != '\0')
	{
		dest[destlen] = src[index];
		index++;
		destlen++;
	}
	dest[destlen] = '\0';
	return (dest);
}
