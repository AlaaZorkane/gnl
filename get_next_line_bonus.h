/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:22:23 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/01 18:52:05 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_BONUS_H
# define FT_GET_NEXT_LINE_BONUS_H
# define FD_LIMIT 10240
# include <stdlib.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *src);
size_t			ft_strlen(const char *str);
char			*ft_strcat(char *dest, const char *src);

#endif
