/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:49:35 by cayako            #+#    #+#             */
/*   Updated: 2020/01/19 18:49:38 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

unsigned long long	*ft_instmino(int i)
{
	unsigned long long			*trmino;
	const unsigned long long	tmp[19] = {
			13835269161514696704ULL, 17293822569102704640ULL,
			9223512776490647552ULL, 13835163608398430208ULL,
			4611897126807404544ULL, 6917740133873614848ULL,
			9223583144161050624ULL, 16140971433240035328ULL,
			4611897125733662720ULL, 4611932309032009728ULL,
			9223583145234792448ULL, 9223618327459397632ULL,
			13835198794918002688ULL, 16140936248867946496ULL,
			4611756390392791040ULL, 2306089299818315776ULL,
			9223512777564356608ULL, 16141041801984212992ULL,
			13835128425100083200ULL
	};

	if (!(trmino = (unsigned long long *)malloc(sizeof(unsigned long long)
			* 20)))
		return (NULL);
	while (++i < 19)
		trmino[i] = tmp[i];
	return (trmino);
}

static void			ft_getxy(t_path *p, int size, int x, int y)
{
	int		*xy;

	xy = p->xy0;
	size = size < 13 ? size : 13;
	while (y < size + 1)
	{
		while (x < size)
		{
			*(xy++) = x;
			*(xy++) = y;
			++x;
		}
		x = 0;
		++y;
	}
}

void				ft_addinc(t_path *p)
{
	++p->inc;
	ft_getxy(p, p->minsq + p->inc, 0, 0);
	p->xy = p->xy0;
	(*p->t)->y = p->minsq + p->inc;
	ft_addmask(p, p->minsq + p->inc);
}

t_path				*ft_getpath(void)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(*path))))
		return (NULL);
	path->xy0 = (int *)malloc(sizeof(int) * 512);
	path->xy = path->xy0;
	ft_getxy(path, 15, 0, 0);
	path->mask = ft_getmask();
	path->field = ft_getfield();
	path->minsq = ft_getminsq(1);
	path->inc = 0;
	path->t = NULL;
	path->trmino = ft_instmino(-1);
	return (path);
}
