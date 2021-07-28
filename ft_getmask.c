/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:47:20 by cayako            #+#    #+#             */
/*   Updated: 2020/01/19 18:47:23 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void						ft_addmask(t_path *path, int size)
{
	(path->field)[0] = (path->field)[5] | (path->mask)[size][0];
	(path->field)[1] = (path->field)[6] | (path->mask)[size][1];
	(path->field)[2] = (path->field)[7] | (path->mask)[size][2];
	(path->field)[3] = (path->field)[8] | (path->mask)[size][3];
}

static unsigned long long	ft_makesq(int x, int y)
{
	unsigned long long	smpl;
	unsigned long long	line;
	int					i;

	i = 0;
	smpl = (~0ULL >> (unsigned long long)x) >> 48ULL << 48ULL;
	line = ~0ULL;
	while (i < y && i < 4)
	{
		line = line >> 16ULL | smpl;
		++i;
	}
	return (line);
}

unsigned long long			**ft_getmask(void)
{
	unsigned long long		**mask;
	int						i;
	int						j;

	i = 0;
	j = 0;
	mask =
		(unsigned long long **)malloc(sizeof(unsigned long long *) * 16);
	while (i < 16)
		mask[i++] =
			(unsigned long long *)malloc(sizeof(unsigned long long) * 4);
	while (j < 16)
	{
		i = 0;
		while (i < 4)
		{
			mask[j][i] = ft_makesq(j, j - i * 4);
			++i;
		}
		++j;
	}
	return (mask);
}
