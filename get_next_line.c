/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:00:14 by sbourziq          #+#    #+#             */
/*   Updated: 2023/12/06 21:00:16 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*s_buffer;
	char		*save;
	char		*result;
	int			len;
	int			nb;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (ft_checkline(s_buffer) == -1)
		s_buffer = new_buffer(s_buffer, ft_readfile(fd));
	nb = ft_checkline(s_buffer);
	len = ft_strlen(s_buffer);
	result = new_line(s_buffer, nb, len);
	if (nb == -1 || !result)
	{
		free(s_buffer);
		s_buffer = 0;
	}
	else
	{
		save = s_buffer;
		s_buffer = ft_substr(save, nb + 1, ft_strlen(save));
		free(save);
	}
	return (result);
}
/*
int main(void)
{
    int fd = open("get_next_line.h", O_RDONLY);
    if (fd < 0) 
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Free the line allocated by get_next_line
    }

    close(fd);
    return 0;
}*/