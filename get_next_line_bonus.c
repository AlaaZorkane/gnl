/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:22:59 by azorkane          #+#    #+#             */
/*   Updated: 2019/11/19 19:08:29 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strjoin_special(char **save, char **buffer, char **tmp)
{
	char	*new_str;

	if (!(new_str = malloc(sizeof(*new_str) * (ft_strlen(*save)
		+ ft_strlen(*buffer) + 1))))
		return (1);
	if (*save)
		new_str = ft_strcpy(new_str, *save);
	if (*buffer)
		new_str = ft_strcat(new_str, *buffer);
	*tmp = new_str;
	free(*save);
	*save = *tmp;
	return (0);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

char	*ft_substr(char const *save, unsigned int start, size_t len)
{
	char	*substr;

	substr = malloc(sizeof(*substr) * len + 1);
	if (substr == NULL || save == '\0')
		return (NULL);
	substr = ft_strncpy(substr, (char *)save + start, len);
	substr[len] = '\0';
	return (substr);
}

int		return_line(char **save, int fd, char **line)
{
	int		index;
	char	*tmp;

	index = 0;
	while (save[fd][index] != '\n' && save[fd][index])
		index++;
	if (save[fd][index] == '\n')
	{
		*line = ft_substr(save[fd], 0, index);
		if (save[fd] != NULL)
		{
			tmp = save[fd];
			save[fd] = ft_strdup(tmp + index + 1);
			free(tmp);
		}
	}
	else if (save[fd][index] == '\0')
	{
		*line = ft_strdup(save[fd]);
		free(save[fd]);
		save[fd] = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[FD_LIMIT + 1];
	char		*buffer;
	char		*tmp;
	int			last;

	if (fd < 0 || fd > FD_LIMIT || BUFFER_SIZE < 0 || !line)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((last = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[last] = '\0';
		if (!save[fd])
			save[fd] = ft_strdup(buffer);
		else if (ft_strjoin_special(&save[fd], &buffer, &tmp))
			return (-1);
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	free(buffer);
	if (last < 0)
		return (-1);
	else if (!last && (save[fd] == NULL || save[fd][0] == '\0'))
		return (0);
	return (return_line(save, fd, line));
}
