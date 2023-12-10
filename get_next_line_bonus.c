/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:55:06 by sbourziq          #+#    #+#             */
/*   Updated: 2023/12/08 16:55:50 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfile(int fd)
{
	char	*buff;
	char	*result;
	char	*tmp;
	ssize_t	bytread;

	buff = (char *)malloc((BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	result = 0;
	while (ft_checkline(result) == -1)
	{
		bytread = read(fd, buff, BUFFER_SIZE);
		if (bytread < 0)
			return (free(buff), NULL);
		buff[bytread] = '\0';
		tmp = result;
		result = ft_strjoin(tmp, buff);
		free(tmp);
		if (!result)
			return (free(buff), NULL);
		if (bytread < BUFFER_SIZE)
			break ;
	}
	free(buff);
	return (result);
}

char	*new_line(char *buffer, int nb, int len)
{
	char	*result;

	if (nb == -1 && len == 0)
		return (NULL);
	if (nb == -1 && len != 0)
		result = ft_substr(buffer, 0, len);
	else
		result = ft_substr(buffer, 0, nb + 1);
	return (result);
}

char	*new_buffer(char *old_buffer, char *new_buff)
{
	char	*res;

	if (!new_buff)
		res = 0;
	else
		res = ft_strjoin(old_buffer, new_buff);
	free(old_buffer);
	free(new_buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*s_buffer[1024];
	char		*save;
	char		*result;
	int			len;
	int			nb;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (ft_checkline(s_buffer[fd]) == -1)
		s_buffer[fd] = new_buffer(s_buffer[fd], ft_readfile(fd));
	nb = ft_checkline(s_buffer[fd]);
	len = ft_strlen(s_buffer[fd]);
	result = new_line(s_buffer[fd], nb, len);
	if (nb == -1 || !result)
	{
		free(s_buffer[fd]);
		s_buffer[fd] = 0;
	}
	else
	{
		save = s_buffer[fd];
		s_buffer[fd] = ft_substr(save, nb + 1, ft_strlen(save));
		free(save);
	}
	return (result);
}
