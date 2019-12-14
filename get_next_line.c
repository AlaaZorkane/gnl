/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:22:59 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/08 23:55:51 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strjoin_special(char **save, char **buffer, char **tmp)
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

static char		*ft_strncpy(char *dest, const char *src, size_t n)
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

static char		*ft_substr(char const *save, unsigned int start, size_t len)
{
	char	*substr;

	substr = malloc(sizeof(*substr) * len + 1);
	if (substr == NULL || save == '\0')
		return (NULL);
	substr = ft_strncpy(substr, (char *)save + start, len);
	substr[len] = '\0';
	return (substr);
}

static int		return_line(char **save, char **line)
{
	int		index;
	char	*tmp;

	index = 0;
	while (save[0][index] != '\n' && save[0][index])
		index++;
	if (save[0][index] == '\n')
	{
		*line = ft_substr(save[0], 0, index);
		if (save[0] != NULL)
		{
			tmp = save[0];
			save[0] = ft_strdup(tmp + index + 1);
			free(tmp);
		}
	}
	else if (save[0][index] == '\0')
	{
		*line = ft_strdup(save[0]);
		free(save[0]);
		save[0] = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*save[1];
	char		*buffer;
	char		*tmp;
	int			last;

	if (fd < 0 || fd > FD_LIMIT || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((last = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[last] = '\0';
		if (!save[0])
			save[0] = ft_strdup(buffer);
		else if (ft_strjoin_special(&save[0], &buffer, &tmp))
			return (-1);
		if (ft_strchr(save[0], '\n'))
			break ;
	}
	free(buffer);
	if (last < 0)
		return (-1);
	else if (!last && (save[0] == NULL || save[0][0] == '\0'))
		return (!(*line = ft_strdup("")));
	return (return_line(save, line));
}
