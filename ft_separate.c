/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:40:13 by gsinged           #+#    #+#             */
/*   Updated: 2019/12/19 19:41:59 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_gsinged.h"

static int					ft_shift(char **chtr)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = -1;
	while (i < 20)
	{
		if ((*chtr)[i] == '#')
		{
			if (x < 0)
			{
				x = i / 5;
				y = i % 5;
			}
			else if (y > i % 5)
				y = i % 5;
		}
		i++;
	}
	return (x * 16 + y);
}

static unsigned long long	ft_returnull(char **chtr)
{
	unsigned long long	ullt;
	int					i;

	if (ft_strlen(*chtr) != 20)
	{
		ft_strclr2star(chtr);
		ft_strdel(chtr);
		return (0);
	}
	i = 0;
	ullt = 0;
	while (i < 20)
	{
		if ((*chtr)[i] == '#')
			ullt = ullt << 1 | 1;
		else if ((*chtr)[i] == '.')
			ullt = ullt << 1;
		if ((*chtr)[i] == '\n')
			ullt = ullt << 12;
		i++;
	}
	ullt = ullt << (unsigned long long)ft_shift(chtr);
	ft_strclr2star(chtr);
	ft_strdel(chtr);
	return (ullt);
}

static int					ft_trminocomb(t_comb **tcomb, \
					unsigned long long **trmino, unsigned long long ullt, int i)
{
	int		j;

	j = 0;
	while (ullt != (*trmino)[j] && j < 19)
		j++;
	if (ullt == (*trmino)[j])
	{
		if (!(*tcomb = (t_comb*)malloc(sizeof(t_comb))))
			return (0);
		(*tcomb)->trmino = j;
		(*tcomb)->place = 'A' + i;
		if (!i)
			(*tcomb)->place2 = 'A';
		else
			(*tcomb)->place2 = (*(tcomb - 1))->trmino == (*tcomb)->trmino ? \
			(*(tcomb - 1))->place2 : (*(tcomb - 1))->place2 + 1;
		(*tcomb)->x = 0;
		(*tcomb)->y = 0;
		return (1);
	}
	return (0);
}

static int					ft_tcomb_i(t_comb **tcomb, int quant)
{
	if (!((*tcomb) = (t_comb*)malloc(sizeof(t_comb))))
		return (0);
	(*tcomb)->trmino = quant;
	(*tcomb)->place = '\0';
	(*tcomb)->x = 0;
	(*tcomb)->y = 0;
	if (!((*(tcomb + quant + 1)) = (t_comb*)malloc(sizeof(t_comb))))
		return (0);
	(*(tcomb + quant + 1))->trmino = 0;
	(*(tcomb + quant + 1))->place = '\0';
	(*(tcomb + quant + 1))->x = 0;
	(*(tcomb + quant + 1))->y = 0;
	return (1);
}

t_comb						**ft_separate(int quant, char **line, \
										unsigned long long **trmino)
{
	t_comb				**tcomb;
	char				*chtr;
	int					i;
	unsigned long long	ullt;

	if (!(tcomb = (t_comb**)malloc(sizeof(t_comb*) * (quant + 2))))
		return (ft_printerror_tcomb(&tcomb, quant, line));
	if (!(ft_tcomb_i(tcomb, quant)))
		return (ft_printerror_tcomb(&tcomb, quant, line));
	i = 0;
	while (i < quant)
	{
		if (!(chtr = ft_strsub(*line, i * 21, 20)))
			return (ft_printerror_tcomb(&tcomb, quant, line));
		if (!(ullt = ft_returnull(&chtr)))
			return (ft_printerror_tcomb(&tcomb, quant, line));
		if (!(ft_trminocomb((tcomb + i + 1), trmino, ullt, i)))
			return (ft_printerror_tcomb(&tcomb, quant, line));
		i++;
	}
	ft_strclr2star(line);
	ft_strdel(line);
	return (tcomb);
}
