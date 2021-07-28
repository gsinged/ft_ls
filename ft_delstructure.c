/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstructure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:15:01 by gsinged           #+#    #+#             */
/*   Updated: 2020/01/07 15:15:02 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_gsinged.h"

void		ft_delt_comb(t_comb ***t)
{
	int		quant;
	int		i;

	if (t && *t)
	{
		i = 0;
		quant = (*t[0])->trmino;
		while (i < quant + 2)
		{
			if ((*t)[i])
			{
				free((*t)[i]);
				(*t)[i] = NULL;
				i++;
			}
		}
		free(*t);
		*t = NULL;
	}
}
