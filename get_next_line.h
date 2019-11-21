/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:22:23 by azorkane          #+#    #+#             */
/*   Updated: 2019/11/13 15:02:42 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define FD_LIMIT 10240
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *src);
size_t			ft_strlen(const char *str);
char			*ft_strcat(char *dest, const char *src);

#endif
