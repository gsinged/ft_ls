/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:14:21 by gsinged           #+#    #+#             */
/*   Updated: 2020/01/14 12:31:52 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_gsinged.h"

static int	ft_octothorpe(int ret, int kol, char **buf, int i)
{
	int		j;
	int		oct;

	while (i < ret)
	{
		j = 0;
		oct = 0;
		while (j < 20)
		{
			if ((j + 1) % 5 == 0 && (*buf)[i] != '\n')
				return (0);
			if ((*buf)[i] != '.' && (*buf)[i] != '#' && (j + 1) % 5 != 0)
				return (0);
			if ((*buf)[i] == '#')
				oct++;
			i++;
			j++;
		}
		if (oct != 4)
			return (0);
		if (kol > 1 && (i + 1) % 21 == 0 && i < ret && (*buf)[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_auxiliary_con(char **buf, int i, int j)
{
	int		con;

	con = 0;
	if ((j - 1) >= 0 && (*buf)[i * 21 + j - 1] == '#')
		con++;
	if ((j + 1) < 20 && (*buf)[i * 21 + j + 1] == '#')
		con++;
	if ((j - 5) >= 0 && (*buf)[i * 21 + j - 5] == '#')
		con++;
	if ((j + 5) < 20 && (*buf)[i * 21 + j + 5] == '#')
		con++;
	return (con);
}

static int	ft_connections(int kol, char **buf)
{
	int		i;
	int		j;
	int		con;

	i = 0;
	while (i < kol)
	{
		j = 0;
		con = 0;
		while (j < 20)
		{
			if ((*buf)[i * 21 + j] == '#')
				con += ft_auxiliary_con(buf, i, j);
			j++;
		}
		i++;
		if (con != 6 && con != 8)
			return (0);
	}
	return (1);
}

static int	ft_auxiliary_open(int fd, char **buf, char **line)
{
	if (!(*line = ft_strdup(*buf)))
		return (0);
	ft_strclr2star(buf);
	ft_strdel(buf);
	close(fd);
	return (1);
}

int			ft_openfile(char *file, char **line)
{
	int		fd;
	int		ret;
	char	*buf;
	int		kol;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printerror(fd, NULL));
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (0);
	if ((ret = read(fd, buf, BUFF_SIZE)) < 20 || ret > 545)
		return (ft_printerror(fd, &buf));
	buf[ret] = '\0';
	if (ret != 20 && (ret - 20) % 21 != 0)
		return (ft_printerror(fd, &buf));
	kol = 1;
	if (ret > 20)
		kol = (ret - 20) / 21 + 1;
	if (!(ft_octothorpe(ret, kol, &buf, 0)))
		return (ft_printerror(fd, &buf));
	if (!(ft_connections(kol, &buf)))
		return (ft_printerror(fd, &buf));
	if (!(ft_auxiliary_open(fd, &buf, line)))
		return (ft_printerror(fd, &buf));
	return (kol);
}
