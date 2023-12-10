/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:57:23 by sbourziq          #+#    #+#             */
/*   Updated: 2023/12/08 16:58:42 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

ssize_t	ft_strlen(char *s);
char	*ft_substr(char *s, int start, int end);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_checkline(char *str);
char	*ft_readfile(int fd);

#endif
