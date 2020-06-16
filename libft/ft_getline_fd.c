/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getline_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:11:22 by omulder       #+#    #+#                 */
/*   Updated: 2019/03/27 17:57:48 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline_fd.h"

static int	check_buffer(char **line, char **buff)
{
	char	*temp;
	char	*temp2;

	temp = ft_strchr(*buff, '\n');
	if (!*line)
		*line = ft_strnew(0);
	if (temp != NULL)
		*temp = '\0';
	temp2 = *line;
	*line = ft_strjoin(*line, *buff);
	if (!*line)
		return (-1);
	ft_strdel(&temp2);
	if (temp == NULL)
	{
		ft_strclr(*buff);
		return (0);
	}
	ft_strdel(buff);
	return (1);
}

int			ft_getline_fd(int fd, char **line)
{
	char	*buff;
	int		ret;

	buff = ft_strnew(BUFF_SIZE);
	if (!buff)
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	while (ret != 0)
	{
		if (ret == -1)
			return (ret);
		ret = check_buffer(line, &buff);
		if (ret != 0)
			return (ret);
		ret = read(fd, buff, BUFF_SIZE);
	}
	if (*line && ft_strlen(*line) > 0)
		return (1);
	return (0);
}
