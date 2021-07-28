/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:35:19 by gsinged           #+#    #+#             */
/*   Updated: 2019/12/19 19:41:59 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_gsinged.h"

int			ft_printerror(int fd, char **buf)
{
	if (fd >= 0)
		close(fd);
	if (buf)
		ft_strdel(buf);
	write(1, "error\n", 6);
	return (0);
}

t_comb		**ft_printerror_tcomb(t_comb ***tcomb, int quant, char **line)
{
	int		i;

	i = 0;
	if (tcomb && *tcomb)
	{
		while (i < quant + 2)
		{
			if ((*tcomb)[i])
			{
				free((*tcomb)[i]);
				(*tcomb)[i] = NULL;
			}
			i++;
		}
		free(*tcomb);
		*tcomb = NULL;
	}
	if (line && *line)
	{
		ft_strclr2star(line);
		ft_strdel(line);
	}
	write(1, "error\n", 6);
	return (NULL);
}
