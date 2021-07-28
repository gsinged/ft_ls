/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:47:03 by cayako            #+#    #+#             */
/*   Updated: 2020/01/19 18:47:05 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

unsigned long long	*ft_getfield(void)
{
	unsigned long long	*field;
	int					i;

	i = 0;
	field = (unsigned long long *)malloc(sizeof(unsigned long long) * 9);
	while (i < 9)
		field[i++] = 0ULL;
	return (field);
}

void				ft_field_to_null(t_path *path)
{
	path->field[0] = 0ULL;
	path->field[1] = 0ULL;
	path->field[2] = 0ULL;
	path->field[3] = 0ULL;
	path->field[4] = 0ULL;
	path->field[5] = 0ULL;
	path->field[6] = 0ULL;
	path->field[7] = 0ULL;
	path->field[8] = 0ULL;
}

unsigned long long	ft_getline(t_path *path, int line)
{
	int		i;
	int		j;

	if (!line)
		return (path->field[0]);
	if (line == 4)
		return (path->field[1]);
	if (line == 8)
		return (path->field[2]);
	if (line == 12)
		return (path->field[3]);
	i = line / 4;
	j = line % 4;
	return (path->field[i] << (unsigned long long)j * 16 |
			path->field[i + 1] >> (unsigned long long)(4 - j) * 16);
}

int					ft_setline(t_path *p, unsigned long long trmino,
						t_comb *cur)
{
	if (!cur->y)
		(p->field)[5] = (p->field)[5] | trmino >>
				(unsigned long long)cur->x;
	else if (cur->y == 12)
		(p->field)[8] = (p->field)[8] | trmino >>
				(unsigned long long)cur->x;
	else
	{
		(p->field)[cur->y / 4 + 5] = (p->field)[cur->y / 4 + 5] |
				trmino >> (unsigned long long)((cur->y % 4) * 16 + cur->x);
		trmino = trmino << (unsigned long long)((4 - cur->y % 4) * 16);
		trmino = trmino >> (unsigned long long)cur->x;
		(p->field)[cur->y / 4 + 6] = (p->field)[cur->y / 4 + 6] | trmino;
	}
	ft_addmask(p, p->minsq + p->inc);
	return (1);
}
