/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcomb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:48:48 by cayako            #+#    #+#             */
/*   Updated: 2020/01/19 18:48:50 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_fcomb(t_path *p, t_comb **cur)
{
	if (!(*cur)->place)
		return (1);
	p->xy = p->xy0;
	if (!ft_find_place(p, *cur))
		return (0);
	if (ft_fcomb(p, ++cur))
		return (1);
	--cur;
	while (ft_move_trmino(p, *cur))
	{
		if (ft_fcomb(p, ++cur))
			return (1);
		--cur;
	}
	return (0);
}

void			ft_fcomb_start(t_path *p)
{
	ft_field_to_null(p);
	p->inc = 0;
	p->minsq = ft_getminsq((*p->t)->trmino);
	(*p->t)->y = p->minsq;
	ft_addmask(p, p->minsq);
	(p->field)[4] = ft_getline(p, 0);
	while (!ft_fcomb(p, p->t + 1) && p->inc < 3)
	{
		ft_field_to_null(p);
		ft_addinc(p);
		(p->field)[4] = ft_getline(p, 0);
	}
}
