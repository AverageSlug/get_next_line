/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:10:14 by nlaurids          #+#    #+#             */
/*   Updated: 2020/02/18 18:41:36 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int		get_next_line(int fd, char **line);
int		ft_checkifendofline(char rest[BUFFER_SIZE + 1]);
void	ft_completeline(char **line, char rest[BUFFER_SIZE + 1]);
int		ft_reader(int fd, char buf[BUFFER_SIZE + 1],
		char rest[BUFFER_SIZE + 1]);
char	*ft_memcat(char *line, char rest[BUFFER_SIZE + 1]);
int		ft_strlen(char *str);

#endif
