/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:19:58 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 17:45:58 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	buff_join(int ret, char **save, char *buff)
{
	char	*temp;

	temp = ft_strjoin(*save, buff);
	if (temp == NULL)
	{
		ft_freearr(*save);
		ft_freearr(buff);
		return (-1);
	}
	ft_freearr(*save);
	ft_freearr(buff);
	*save = temp;
	if (ret > 0)
		return (1);
	else
		return (ret);
}

static int	read_buff(int fd, char **save)
{
	char	*buff;
	int		ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		buff = NULL;
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret < 0 || buff == NULL)
	{
		ft_freearr(buff);
		return (-1);
	}
	buff[ret] = '\0';
	return (buff_join(ret, save, buff));
}

static void	division_plus(char **save, char **line, int ret)
{
	char	*output;
	char	*backup;
	int		i;

	i = 0;
	if (ret > 0)
	{
		while ((*save)[i] != '\n')
			i++;
		output = ft_substr(*save, 0, i);
		if (output == NULL)
		{
			ft_freearr(*save);
			return ;
		}
		*line = output;
		backup = ft_strdup(*save + i + 1);
		if (backup == NULL)
		{
			ft_freearr(*save);
			return ;
		}
		ft_freearr(*save);
		*save = backup;
	}
}

static int	division_zero(char **save, char **line, int ret)
{
	if (ret == 0)
	{
		*line = ft_strdup(*save);
		if (*line == NULL)
		{
			ft_freearr(*save);
			return (-1);
		}
		ft_freearr(*save);
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	int			ret;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (save [fd] == NULL)
	{
		save[fd] = ft_strdup("");
		if (save[fd] == NULL)
			return (-1);
	}
	ret = 1;
	while (ret > 0 && (ft_strchr(save[fd], '\n') == 0))
		ret = read_buff(fd, &save[fd]);
	ret = division_zero(&save[fd], line, ret);
	division_plus(&save[fd], line, ret);
	return (ret);
}
