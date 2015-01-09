/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:21:33 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/31 06:44:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	have_back(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i + 1);
			i++;
		}
	}
	return (0);
}

static char	*ft_strnew_join(char const *s1, char const *s2)
{
	int		len_all;
	char	*temp_s1;
	char	*dst;

	temp_s1 = (char *)s1;
	if (temp_s1 && s2)
	{
		len_all = ft_strlen(temp_s1) + ft_strlen(s2);
		dst = ft_memalloc(len_all + 1);
		if (dst)
		{
			ft_strcat(ft_strcpy(dst, temp_s1), s2);
			free(temp_s1);
			return (dst);
		}
	}
	return (NULL);
}

static char	*ft_strnew_sub(char const *s, unsigned int start, size_t len)
{
	char			*temp_s;
	unsigned int	i;

	i = 0;
	if (s && len)
	{
		temp_s = ft_strnew(len);
		if (temp_s)
		{
			while (i++ < start)
				s++;
			strncpy(temp_s, s, len);
			return (temp_s);
		}
	}
	else if (!len)
	{
		temp_s = (char *)malloc(sizeof(char) * 1);
		temp_s[0] = '\0';
		return (temp_s);
	}
	return (NULL);
}

static int	ft_put_line_rest(char **line, char *buff, char **rest, int *ret_end)
{
	while (!have_back(rest[ret_end[FD]]) && ret_end[RET] > 0)
	{
		ret_end[RET] = read(ret_end[FD], buff, BUFF_SIZE);
		buff[ret_end[RET]] = '\0';
		rest[ret_end[FD]] = ft_strnew_join(rest[ret_end[FD]], buff);
		if ((ft_strlen(buff) < BUFF_SIZE && ret_end[RET] > 0))
		{
			if (have_back(rest[ret_end[FD]]))
				return (0);
			else
				*line = ft_strdup(rest[ret_end[FD]]);
			ret_end[END] = 1;
			free(buff);
			return (1);
		}
	}
	if (ft_strlen(rest[ret_end[FD]]) && !ret_end[RET])
		*line = ft_strdup(rest[ret_end[FD]]);
	free(buff);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*bf;
	static char	*rest[MAX_FILES];
	int			ret_end[3];

	if (!line || !(bf = (char *)malloc(sizeof(1) * (BUFF_SIZE + 1))) || fd < 0)
		return (-1);
	ret_end[RET] = 1;
	ret_end[END] = 0;
	ret_end[FD] = fd;
	*line = ft_strdup("");
	if (!rest[fd])
		rest[fd] = ft_strnew(0);
	if (!ft_put_line_rest(line, bf, rest, ret_end))
	{
		if (ret_end[RET] > 0 && !ret_end[END])
		{
			*line = ft_strnew_sub(rest[fd], 0, have_back(rest[fd]) - 1);
			rest[fd] = ft_strnew_sub(rest[fd], have_back(rest[fd]), BUFF_SIZE);
		}
	}
	if (ret_end[RET] == -1)
		return (-1);
	if (ft_strlen(*line) || ret_end[RET])
		return (1);
	return (0);
}
