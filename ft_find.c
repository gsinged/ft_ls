/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:54:24 by cayako            #+#    #+#             */
/*   Updated: 2020/01/31 22:55:40 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_find_place(t_path *p, t_comb *cur)
{
	p->field[4] = ft_getline(p, *(p->xy + 1));
	while (*(p->xy + 1) < p->minsq + p->inc)
	{
		if (!(p->field[4] << (unsigned long long)(*p->xy) &
				p->trmino[cur->trmino]))
		{
			cur->x = *p->xy;
			cur->y = *(p->xy + 1);
			return (ft_setline(p, p->trmino[cur->trmino], cur));
		}
		p->xy += 2;
		p->field[4] = ft_getline(p, *(p->xy + 1));
	}
	return (0);
}

int				*ft_find_xy(int *xy, int x, int y)
{
	while (*(xy + 1) < 15)
	{
		if (*xy == x && *(xy + 1) == y)
			break ;
		xy += 2;
	}
	return (xy);
}

int				ft_rm_trmino(t_path *p, unsigned long long trmino, t_comb *cur)
{
	if (!cur->y)
		(p->field)[5] = (p->field)[5] ^ trmino >> (unsigned long long)cur->x;
	else if (cur->y == 12)
		(p->field)[8] = (p->field)[8] ^ trmino >> (unsigned long long)cur->x;
	else
	{
		(p->field)[cur->y / 4 + 5] = (p->field)[cur->y / 4 + 5] ^
				trmino >> (unsigned long long)((cur->y % 4) * 16 + cur->x);
		trmino = trmino << (unsigned long long)((4 - cur->y % 4) * 16);
		trmino = trmino >> (unsigned long long)cur->x;
		(p->field)[cur->y / 4 + 6] = (p->field)[cur->y / 4 + 6] ^ trmino;
	}
	ft_addmask(p, p->minsq + p->inc);
	return (1);
}

int				ft_move_trmino(t_path *p, t_comb *cur)
{
	p->xy = ft_find_xy(p->xy0, cur->x, cur->y);
	ft_rm_trmino(p, p->trmino[cur->trmino], cur);
	p->xy += 2;
	return (ft_find_place(p, cur));
}
